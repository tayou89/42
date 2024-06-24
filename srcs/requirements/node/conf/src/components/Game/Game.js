import { useEffect, useState, MyReact } from "../../MyReact/MyReact.js";
import NavigationBar from "../utility/NavigationBar.js";
import ScoreBoard from "./ScoreBoard.js";
import GameBoard from "./GameBoard.js";
import BottomLine from "../Room/BottomLine.js";
import QuitPopUp from "../Room/QuitPopUp.js";
import ResultPopUp from "./ResultPopUp.js";
import EventHandler from "../Room/EventHandler.js";
import { INIT } from "./constant.js";
import "../../css/game/game-page.css";

function Game({ data }) {
    const [ isQuitClicked, setIsQuitClicked ] = useState(false);
    const [ game, setGame ] = useState(getInitialGameData());
    const [ players, setPlayers ] = useState([{}, {}]);
    const [ gameResult, setGameResult ] = useState({});

    useEffect(() => {
        const eventHandler = new EventHandler();

        eventHandler.addKeyEvent(data.socket);
        socket.turnOnRoomChannel(players, setPlayers);
        socket.turnOnGameChannel(game, setGame);
        socket.turnOnResultChannel(setGameResult);
        return (() => {
            eventHandler.removeKeyEvent();
            socket.turnOffRoomChannel();
            socket.turnOffGameChannel();
            socket.turnOffResultChannel();
        });
    }, []);
    return (
        <div className="container-fluid" id="game-page">
            <NavigationBar />
            <ScoreBoard score={ game.score }/>
            <GameBoard players={ players } ball={ game.ball } paddle={ game.paddle }/>
            <BottomLine socket={ socket } setIsQuitClicked={ setIsQuitClicked }/>
            <QuitPopUp socket={ socket } isClicked={ isQuitClicked } set={ setIsQuitClicked } /> 
            <ResultPopUp gameResult={ gameResult } data={ data } players={ players } />
        </div>
    );
}

function getInitialGameData() {
    const initialGameData = {
        ball: { x: INIT.BALL.X, y: INIT.BALL.Y },
        paddle: { p1: INIT.PADDLE1.Y, p2: INIT.PADDLE2.Y },
        score: { p1: 0, p2: 0},
    }
    return (initialGameData);
}

export default Game;