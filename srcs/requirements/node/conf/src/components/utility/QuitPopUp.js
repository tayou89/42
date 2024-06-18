import { useEffect, useState, MyReact } from "../../MyReact/MyReact.js";
import { navigate } from "../../MyReact/MyReactRouter.js";
import "../../css/utility/quit-popup.css";

function QuitPopUp({ setIsQuitClicked }) {
    const handleClickYes = () => {
        navigate("/main");
    }
    const handleClickNo = () => {
        setIsQuitClicked((prev) => (!prev));
    }
    return (
        <div className="container-fluid" id="quit-popup">
            <div className="row" id="quit-query">Do you really want to quit?</div>
            <div className="row" id="quit-popup-button-box">
                <div className="col" id="quit-popup-button" onClick={ handleClickYes }>yes</div>
                <div className="col" id="quit-popup-button" onClick={ handleClickNo }>no</div>
            </div>
        </div>
    );
};

export default QuitPopUp;