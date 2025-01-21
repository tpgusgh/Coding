// (1) 폼과 테이블의 tbody 요소를 찾아서 변수에 할당
const postForm = document.getElementById("postForm");
const postTableBody = document.querySelector("#postTable tbody");

// (2) 폼 제출 이벤트
postForm.addEventListener("submit", function (event) {
    event.preventDefault(); // 페이지 새로고침 막기

    // 1) 입력값 가져오기
    const title = document.getElementById("title").value;
    const content = document.getElementById("content").value;
    const author = document.getElementById("author").value;

    // 2) 테이블 행(tr)과 데이터 셀(td) 생성 및 값 채우기
    const row = document.createElement("tr");

    // 제목
    const titleCell = document.createElement("td");
    titleCell.textContent = title;
    row.appendChild(titleCell);

    // 내용
    const contentCell = document.createElement("td");
    contentCell.textContent = content;
    row.appendChild(contentCell);

    // 작성자
    const authorCell = document.createElement("td");
    authorCell.textContent = author;
    row.appendChild(authorCell);

    // 작성일자
    const dateCell = document.createElement("td");
    const now = new Date();
    dateCell.textContent = now.toLocaleString(); // 현재 날짜와 시간을 읽음
    row.appendChild(dateCell);

    // 3) 테이블의 tbody에 추가 (최신 글이 위에 오게 하려면 prepend)
    postTableBody.prepend(row);

    // 4) 폼 초기화
    postForm.reset();
});
