import { useEffect, useState, MyReact } from "../../MyReact/MyReact.js";

const sampleMatchRecords = [
	{
		"id": 1,
		"p1_score": 10,
		"p2_score": 6,
		"date": "2024-05-01T12:24:37.756097Z",
		"p1": 1,
		"p2": 2
	},
	{
		"id": 2,
		"p1_score": 8,
		"p2_score": 10,
		"date": "2024-05-02T12:24:37.756097Z",
		"p1": 1,
		"p2": 2
	}
];

function MatchRecords({ userId }) {
	const [userMatchRecords, setUserMatchRecords] = useState([]);
	const userMatchRecordsApiUrl = `http://localhost:8000/api/users/${userId}/matches`;

	const fetchMatchRecords = () => {
		fetch(userMatchRecordsApiUrl, {
			method: 'GET',
			credentials: 'include'
		})
			.then(response => response.json())
			.catch(console.log)
			.then(data => {
				setUserMatchRecords(() => sampleMatchRecords);
			})
			.catch(error => {
				console.log("in MatchRecords function", error);
				setUserMatchRecords([]);
			});
	}

	useEffect(() => {
		fetchMatchRecords();
	}, [])

	return (
		<div>
			<div className="container fs-4">
				Match Records
			</div>
			<div className="pt-2 pb-2 border-top border-bottom rounded">
				{userMatchRecords.map((match) =>
					<MatchRecord match={match} userId={userId} />
				)}
			</div>
		</div>
	);
}

function MatchRecord({ match, userId }) {
	const isP1Win = match.p1_score > match.p2_score;
	const isUserP1 = match.p1 == userId;
	const isUserWin = (isUserP1 ? isP1Win : !isP1Win);
	const winTextColor = (isUserWin ? " text-success " : " text-danger ");

	const p1DataApiUrl = `http://localhost:8000/api/users/${match.p1}`;
	const p2DataApiUrl = `http://localhost:8000/api/users/${match.p2}`;
	const [p1NickName, setP1NickName] = useState("Player 1");
	const [p2NickName, setP2NickName] = useState("Player 2");

	useEffect(() => {
		fetch(p1DataApiUrl, {
			method: 'GET',
			credentials: 'include'
		})
			.then(response => response.json())
			.catch(console.log)
			.then(data => setP1NickName(() => {
				console.log(data.name);
				return data.name ? data.name : "unknown";
			}))
			.catch(console.log);

		fetch(p2DataApiUrl, {
			method: 'GET',
			credentials: 'include'
		})
			.then(response => response.json())
			.catch(console.log)
			.then(data => setP2NickName(() => {
				console.log(data.name);
				return data.name ? data.name : "unknown";
			}))
			.catch(console.log);
	}, [])
	return (
		<div className={"my-1 py-1 text-light text-center container bg-dark border-start rounded" + (isUserWin ? " border-success" : " border-danger")}>
			<div className="row">
				<div className="col-2">
					<div className={"my-3" + winTextColor}>
						<b>{isUserWin ? "Win" : "Lose"}</b>
					</div>
				</div>
				<div className="col-10 mt-1">
					<div className="row">
						<div className="col-4 text-end">{p1NickName}</div>
						<div className="col-4">{match.p1_score} vs {match.p2_score}</div>
						<div className="col-4 text-start">{p2NickName}</div>
					</div>
					<div>
						{match.date}
					</div>
				</div>
			</div>
		</div>
	);
}

export default MatchRecords;