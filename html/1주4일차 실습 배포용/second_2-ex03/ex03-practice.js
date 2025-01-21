const test = document.getElementById("test");
const result = document.getElementById("result");
const resetButton = document.getElementById("resetButton");

let startTime; // 초록 화면 시작 시간
let endTime; // 클릭 순간 시간
let reactionTimes = []; // 반응 시간 저장
let isWaiting = false; // 초록 화면 여부
let testCount = 0; // 테스트 횟수
let waitingTimeout = null; // setTimeout 참조

// 최초 상태: 빨간 화면
test.innerText = "클릭하여 시작";
test.className = "red";

// [1] 클릭 이벤트 메인 로직
test.addEventListener("click", () => {
    if (isWaiting) {
        // 초록 화면에서 클릭
        endTime = Date.now();
        const reactionTime = endTime - startTime;
        reactionTimes.push(reactionTime);

        testCount++;
        const log = document.createElement("p");
        log.innerText = `반응 시간: ${reactionTime}ms`;
        result.appendChild(log);

        isWaiting = false;

        if (testCount < 5) {
            test.innerText = "클릭하여 다시 시작";
            test.className = "ready";
        } else {
            const averageTime = 
                reactionTimes.reduce((sum, time) => sum + time, 0) / reactionTimes.length;

            const summary = document.createElement("p");
            summary.innerText = `테스트 완료! 평균 반응 시간: ${averageTime.toFixed(2)}ms`;
            result.appendChild(summary);

            const instruction = document.createElement("p");
            instruction.innerText = "재시작 하려면 아래 리셋 버튼을 누르세요.";
            result.appendChild(instruction);

            test.style.pointerEvents = "none"; // 클릭 방지
        }
        return;
    }

    if (test.classList.contains("red")) {
        if (waitingTimeout) {
            clearTimeout(waitingTimeout);
            waitingTimeout = null;

            test.classList.remove("red");
            test.classList.add("gray");
            test.innerText = "잘못된 클릭!";

            setTimeout(() => {
                test.classList.remove("gray");
                test.classList.add("red");
                test.innerText = "클릭하여 시작";
            }, 1000);
        } else {
            startWaiting();
        }
        return;
    }

    if (test.classList.contains("ready")) {
        startWaiting();
    }
});

// [2] 랜덤 딜레이 후 초록 화면 전환
function startWaiting() {
    test.innerText = "기다리세요...";
    test.className = "red";

    const randomDelay = Math.floor(Math.random() * 4000) + 1000;

    waitingTimeout = setTimeout(() => {
        test.innerText = "지금 클릭하세요!";
        test.className = "green";
        startTime = Date.now();
        isWaiting = true;
        waitingTimeout = null;
    }, randomDelay);
}

// [3] 리셋 버튼
resetButton.addEventListener("click", () => {
    test.innerText = "클릭하여 시작";
    test.className = "red";
    test.style.pointerEvents = "auto";
    result.innerText = "";

    reactionTimes = [];
    isWaiting = false;
    testCount = 0;

    if (waitingTimeout) {
        clearTimeout(waitingTimeout);
        waitingTimeout = null;
    }
});
