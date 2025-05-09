// 지뢰찾기 기본 설정
const rows = 8;
const cols = 8;
const mineCount = 10;

let boardData = []; // 지뢰 및 숫자 정보가 저장되는 2차원 배열

const minefield = document.getElementById("minefield");
const resetBtn = document.getElementById("resetBtn");

//=============== 초기화 & 보드 생성 로직 ===============//
function initGame() {
    // 내부 데이터 초기화
    boardData = [];
    minefield.innerHTML = ""; // 화면에서 초기화

    // 1) 2차원 배열 구조 준비
    for (let r = 0; r < rows; r++) {
        boardData[r] = [];
        for (let c = 0; c < cols; c++) {
            boardData[r][c] = {
                mine: false,
                revealed: false,
                flagged: false,
                neighbor: 0, // 주변 지뢰 수
            };
        }
    }

    // 2) 지뢰 배치
    placeMines();

    // 3) 주변 지뢰 수 계산
    calculateNeighborCounts();

    // 4) HTML 엘리먼트(칸) 생성
    renderBoard();
}

// 무작위 위치에 mineCount개의 지뢰 배치
function placeMines() {
    let placed = 0;
    while (placed < mineCount) {
        const r = Math.floor(Math.random() * rows);
        const c = Math.floor(Math.random() * cols);
        if (!boardData[r][c].mine) {
            boardData[r][c].mine = true;
            placed++;
        }
    }
}

// 주변 8칸의 지뢰 수 계산
function calculateNeighborCounts() {
    const directions = [
        [-1, -1],
        [-1, 0],
        [-1, 1],
        [0, -1],
        [0, 1],
        [1, -1],
        [1, 0],
        [1, 1],
    ];

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (boardData[r][c].mine) {
                boardData[r][c].neighbor = -1; // 지뢰 표시
            } else {
                let count = 0;
                directions.forEach(([dr, dc]) => {
                    const nr = r + dr;
                    const nc = c + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        if (boardData[nr][nc].mine) {
                            count++;
                        }
                    }
                });
                boardData[r][c].neighbor = count;
            }
        }
    }
}

// 보드(HTML) 생성
function renderBoard() {
    for (let r = 0; r < rows; r++) {
        const rowDiv = document.createElement("div");
        rowDiv.classList.add("row");
        for (let c = 0; c < cols; c++) {
            const cellDiv = document.createElement("div");
            cellDiv.classList.add("cell");
            cellDiv.setAttribute("data-row", r);
            cellDiv.setAttribute("data-col", c);

            // 왼쪽 클릭
            cellDiv.addEventListener("click", leftClick);
            // 오른쪽 클릭(브라우저 기본 메뉴 방지)
            cellDiv.addEventListener("contextmenu", (e) => {
                e.preventDefault();
                rightClick(e);
            });

            rowDiv.appendChild(cellDiv);
        }
        minefield.appendChild(rowDiv);
    }
}

//=============== 클릭 이벤트들 ===============//

// (1) 왼쪽 클릭(칸 열기)
function leftClick(e) {
    const cellDiv = e.target;
    const r = parseInt(cellDiv.getAttribute("data-row"));
    const c = parseInt(cellDiv.getAttribute("data-col"));

    const cellData = boardData[r][c];

    // To do 1. 왼쪽 클릭
    // 이미 열려있거나 깃발이 있는 칸은 무시
    // 지뢰를 클릭했다면 -> 게임 종료
    // 1. 지뢰 위치 클릭 시 게임 오버 alert 창 출력
    // 2. 주변 깃발 갯수와 숫자가 동일한 경우 주변 칸 연쇄적으로 오픈
    // 3. 승리 체크 (모든 지뢰 찾았을 시 (checkwin()함수 활용))
}

function rightClick(e) {
    const cellDiv = e.target;
    const r = parseInt(cellDiv.getAttribute("data-row"));
    const c = parseInt(cellDiv.getAttribute("data-col"));
    const cellData = boardData[r][c];

    // To do 2. 오른쪽 클릭(깃발 표시)
    // 1. 열려있는 칸 깃발 표시 불가
    // 2. 깃발 있는 칸 클릭 시에는 깃발 없어져야 함
    // 3. 2번의 반대 기능 추가
}

//=============== 보조 함수들 ===============//

// 해당 칸의 모습(스타일, 숫자, 배경 등) 업데이트
function updateCell(cellDiv, r, c) {
    const cellData = boardData[r][c];
    cellDiv.classList.add("revealed");

    if (cellData.mine) {
        cellDiv.classList.add("mine");
        cellDiv.textContent = "💣";
    } else if (cellData.neighbor > 0) {
        cellDiv.textContent = cellData.neighbor;
    } else {
        // 0이면 빈칸
        cellDiv.textContent = "";
    }
}

// 주변 칸 열기(DFS/BFS 형태로 0값 주변 연쇄 오픈)
function openSurrounding(r, c) {
    const directions = [
        [-1, -1],
        [-1, 0],
        [-1, 1],
        [0, -1],
        [0, 1],
        [1, -1],
        [1, 0],
        [1, 1],
    ];

    directions.forEach(([dr, dc]) => {
        const nr = r + dr;
        const nc = c + dc;
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            const neighborData = boardData[nr][nc];
            if (!neighborData.revealed && !neighborData.flagged) {
                neighborData.revealed = true;
                const neighborCellDiv = document.querySelector(
                    `.cell[data-row='${nr}'][data-col='${nc}']`
                );
                updateCell(neighborCellDiv, nr, nc);
                if (neighborData.neighbor === 0 && !neighborData.mine) {
                    openSurrounding(nr, nc);
                }
            }
        }
    });
}

// 모든 지뢰 드러내기
// (win === true) 이면 깃발만 추가 표기
function revealAllMines(win = false) {
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            const cellData = boardData[r][c];
            const cellDiv = document.querySelector(
                `.cell[data-row='${r}'][data-col='${c}']`
            );
            if (cellData.mine && !win) {
                cellData.revealed = true;
                updateCell(cellDiv, r, c);
            }
            if (cellData.mine && win) {
                // 깃발 표시
                cellDiv.classList.add("flag");
            }
        }
    }
}

// 모든 칸 클릭 불가
function disableAllClicks() {
    const allCells = document.querySelectorAll(".cell");
    allCells.forEach((cell) => {
        cell.style.pointerEvents = "none";
    });
}

// 승리 조건: 지뢰가 아닌 칸이 전부 열렸는지
function checkWin() {
    let openedCount = 0;
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            if (!boardData[r][c].mine && boardData[r][c].revealed) {
                openedCount++;
            }
        }
    }
    const totalSafeCells = rows * cols - mineCount;
    return openedCount === totalSafeCells;
}

// 재시작 버튼 클릭
resetBtn.addEventListener("click", () => {
    initGame();
});

// 페이지 로드되면 자동으로 게임 초기화
window.onload = () => {
    initGame();
};
