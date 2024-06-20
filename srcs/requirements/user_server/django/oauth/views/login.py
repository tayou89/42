
import requests
import os

from django.views.generic import RedirectView
from django.core.files.base import ContentFile

from django.shortcuts import redirect

from ..models import User, OTPModel
from user.serializer import UserSerializer

from django.core.mail import send_mail

CLIENT_ID = os.getenv("CLIENT_ID")
CLIENT_SECRET = os.getenv("CLIENT_SECRET")
RETURN_URI = 'http://localhost:8000/api/login/done'


class login_to_42(RedirectView):
	url = f'https://api.intra.42.fr/oauth/authorize?client_id={CLIENT_ID}&redirect_uri={RETURN_URI}&response_type=code'


def after_login(request):
	access_token = get_access_token(request.GET['code'])
	user = get_user_info(access_token)
	user_instance = save_user_info(user)
	make_otp_code(user_instance)
 
	response = redirect('http://localhost:8080/emailotp')
	response.set_cookie('pk', user_instance.pk, httponly=True)
	return response



def get_access_token(code):

	url = 'https://api.intra.42.fr/oauth/token'

	body = {
		'grant_type': 'authorization_code',
		'client_id': f'{CLIENT_ID}',
		'client_secret': f'{CLIENT_SECRET}',
		'code': f'{code}',
		'redirect_uri': f'{RETURN_URI}',
	}

	response = requests.post(url, json=body)

	return response.json()['access_token']


def save_user_info(data):

	name = data['login']
	email = data['email']
	img_url = data['image']['link']

	user, is_created = User.objects.get_or_create(name=name)

	if is_created:
		user.email = email

		response = requests.get(img_url)
		avatar = response.content
		user.avatar.save(f"{name}.jpg", ContentFile(avatar))
		
	user.online = True
	user.save()

	return user



def get_user_info(access_token):

	url = 'https://api.intra.42.fr/v2/me'

	header = {
		'Authorization': f'Bearer {access_token}'
	}

	response = requests.get(url, headers=header)

	return response.json()


def make_otp_code(user_instance):

	user_otp, tmp = OTPModel.objects.get_or_create(user=user_instance)
	user_otp.save()

	send_mail(
		"ft_transcendence OTP",
		f'''your OTP code is
		{user_otp.code}
		input in 3 minute''',
		"Don't Reply <do_not_reply@domain.example>", 
		[user_instance.email]
	)
 