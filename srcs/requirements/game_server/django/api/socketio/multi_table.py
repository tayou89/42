import httpx

import socketio
import asyncio

from . import sio
from .game_state import GameState
from ..models import Room

from asgiref.sync import sync_to_async
from .pong import Pong


class MttPong(Pong):
	
	sessions = {}
	
	def __init__(self, namespace=None):
		super().__init__(namespace)
		self.field_list = ['p1', 'p2', 'p3', 'p4']
		self.MAX_USER = 4

	async def on_disconnect(self, sid):
		super().on_disconnect(sid)
		
		info = await self.get_session(sid)
		room_name = info.get('room')
		me = info.get('me')
  
		if me == 'p1' or me == 'p2':
			sub_game  = self.sub_games.get(room_name + "_sub1", None)
			if sub_game:
				sub_game.pop(me)
		else:
			sub_game  = self.sub_games.get(room_name + "_sub2", None)
			if sub_game:
				sub_game.pop(me)

		sub_game  = self.sub_games.get(room_name + "_sub3", None)
		if sub_game:
			sub_game.pop(me)


	async def on_join_room(self, sid, message):
		super().on_join_room(sid, message)
		
		room_name = message['room']
		room_sessions = self.session.get(room_name, None)
		if room_sessions is None:
			room_sessions = self.session[room_name] = {}

		session_data = await sio.get_session(sid)
		room_sessions[session_data['me']] = sid


	async def on_ready(self, sid, message):
		flag = message
		info = await self.get_session(sid)
		me = info.get('me')
		room_name = info.get('room')
  
		self.rooms[room_name][me]['ready'] = flag
		await self.emit('room', self.rooms[room_name], room=room_name, namespace=self.namespace)
  
		cur_room = self.rooms[room_name]

		flag = True
		for key, value in cur_room.items():
			if value and not value['ready']:
				flag = False
				break;
  
		if flag:
			cur_sesseion = self.session[room_name]
			await asyncio.create_task(self.play_pong(room_name))

	async def make_room_and_play(self, session, room_name):
		await self.enter_room(session['p1'], room_name + 'sub_1')
		await self.save_session(session['p1'], {'me': 'p1', 'room': room_name + 'sub_1'})
		await self.enter_room(session['p2'], room_name + 'sub_1')
		await self.save_session(session['p2'], {'me': 'p2', 'room': room_name + 'sub_1'})
		await self.enter_room(session['p3'], room_name + 'sub_2')
		await self.save_session(session['p3'], {'me': 'p3', 'room': room_name + 'sub_2'})
		await self.enter_room(session['p4'], room_name + 'sub_2')
		await self.save_session(session['p4'], {'me': 'p4', 'room': room_name + 'sub_2'})

		await asyncio.create_task(self.play_pong(room_name + 'sub_1', session['p1'], session['p2']))
		await asyncio.create_task(self.play_pong(room_name + 'sub_2', session['p3'], session['p4']))


	async def play_pong(self, room_name, p1_pid, p2_pid):
		game = self.games[room_name] = GameState()
		game.p1_pid = self.rooms[room_name]['p1']['pid']
		game.p2_pid = self.rooms[room_name]['p2']['pid']
  
		room_db = await sync_to_async(Room.objects.get)(name=room_name)
		room_db.in_game = True
		await sync_to_async(room_db.save)()
  
		await sio.sleep(5)
		
		while game.status != 'end':
			
			if len(self.rooms[room_name]) != 2:
				if 'p1' in self.rooms[room_name]:
					game.unearned_win('p1')
				else:
					game.unearned_win('p2')
				break

			await sio.emit(
				'game',
				game.next_frame(),
				room=room_name,
				namespace=self.namespace
			)

			await sio.sleep(1 / 30)
		
		await sio.emit(
			'result',
			game.get_result(),
			room=room_name,
			namespace=self.namespace
		)


	async def on_key(self, sid, message):
		info = await self.get_session(sid)
		room_name = info.get('room')
  
		game: GameState = self.games[room_name]
		game.set_player_dy(sid, message)

sio.register_namespace(MttPong('/api/mtt'))
