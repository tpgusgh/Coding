// 현재 표시 중인 연도와 월 (1~12)
let currentYear = 2025;
let currentMonth = 1; // 1월

// HTML 요소 참조
const titleElem = document.getElementById("calendar-title"); // <h1 id="calendar-title">
const calendarElem = document.getElementById("calendar"); // <div id="calendar">
const prevBtn = document.getElementById("prevBtn"); // <button id="prevBtn">
const nextBtn = document.getElementById("nextBtn"); // <button id="nextBtn">

// 페이지가 처음 로드될 때 1월 달력 그리기
renderCalendar(currentYear, currentMonth);

// To do 1.
// prevBtn(이전 버튼)에 대한 click 이벤트 추가
// 1월 이전으로 갈 수 없도록 구현
prevBtn.addEventListener("click", () => {
    if (currentMonth > 1) {
        currentMonth--;
        renderCalendar(currentYear, currentMonth);
    }
    else{
        currentYear--;
        currentMonth = 12;
        renderCalendar(currentYear, currentMonth);
    }
});

// To do 2.
// nextBtn(다음 버튼)에 대한 click 이벤트 추가
// 12월 이후로 갈 수 없도록 구현
nextBtn.addEventListener("click", () => {
    if (currentMonth < 12) {
        currentMonth++;
        renderCalendar(currentYear, currentMonth);
    }
    else{
        currentYear++;
        currentMonth = 1;
        renderCalendar(currentYear, currentMonth);
    }
});

/**
 * 달력을 생성하여 화면에 표시하는 함수
 * @param {number} year  - 연도 (예: 2025)
 * @param {number} month - 월 (1~12)
 */
function renderCalendar(year, month) {
    // ----------------------------
    // 1) 달력 제목 “YYYY.MM” 형식으로 표시
    // ----------------------------
    const monthString = String(month).padStart(2, "0");
    titleElem.textContent = `${year}.${monthString}`;

    // ----------------------------
    // 2) 기존 달력 내용 지우기
    // ----------------------------
    calendarElem.innerHTML = "";

    // ----------------------------
    // 3) 요일 헤더(일~토) 생성
    // ----------------------------
    const days = ["일", "월", "화", "수", "목", "금", "토"];
    days.forEach((day) => {
        const dayDiv = document.createElement("div");
        dayDiv.classList.add("day");
        dayDiv.textContent = day;
        calendarElem.appendChild(dayDiv);
    });

    // To do 3.
    // parameter로 전달받은 월에 대한 첫째 날, 마지막 날짜 구하기
    const firstDay = new Date(year, month - 1, 1);
    const lastDay = new Date(year, month, 0);
    const totalDays = lastDay.getDate(); 
    const startDay = firstDay.getDay(); 

    // To do 4.
    // 첫 주의 빈칸 채우기
    for (let i = 0; i < startDay; i++) {
        const emptyDiv = document.createElement("div");
        emptyDiv.classList.add("empty");
        calendarElem.appendChild(emptyDiv);
    }

    // ----------------------------
    // 6) 1일부터 마지막 날짜까지 생성하여 달력에 추가
    // ----------------------------
    for (let dayNum = 1; dayNum <= totalDays; dayNum++) {
        const dateDiv = document.createElement("div");
        dateDiv.classList.add("date");
        dateDiv.textContent = dayNum;

        // To do 5.
        // 날짜마다 요일을 계산하여 토요일이거나 일요일일 경우
        // 해당 div에 클래스를 지정하여 파란색 or 빨간색으로 출력 될 수 있도록
        const dayOfWeek = (startDay + dayNum - 1) % 7; 
        if (dayOfWeek === 0) {
            dateDiv.classList.add("weekend-sat");
        } else if (dayOfWeek === 6) {
            dateDiv.classList.add("weekend-sun");
        }

        calendarElem.appendChild(dateDiv);
    }
}
