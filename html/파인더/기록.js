// localStorage에서 저장된 데이터 가져오기
const text1 = localStorage.getItem('text1');
const text2 = localStorage.getItem('text2');

// localStorage에서 가져오기
let number = parseInt(localStorage.getItem('number')) || 1;

if (text1 && text2) {
    const regex = new RegExp(`(${text2})`, 'gi');
    const highlightedText = text1.replace(regex, '<span class="highlight">$1</span>');
    document.getElementById('outputtext').innerHTML = highlightedText;

    // localStorage에서 가져오기
    let history = JSON.parse(localStorage.getItem('history')) || [];

    // 중복 확인
    const isDuplicate = history.some(entry => entry.text1 === text1 && entry.text2 === text2);

    if (!isDuplicate) {
        history.push({text1, text2});
        localStorage.setItem('history', JSON.stringify(history));
    }

    // history 출력하기
    let historyText = history.map((entry, index) => {
        const highlightedHistory = entry.text1.replace(new RegExp(`(${entry.text2})`, 'gi'), '<span class="highlight">$1</span>');
        return `${index + 1}. ${highlightedHistory}`;
    }).join("<br> <br>");

    document.getElementById('outputtext').innerHTML = `<p>${historyText}</p>`;
} else {
    document.getElementById('outputtext').innerText = "텍스트를 찾을 수 없습니다.";
}

// localStorage 초기화 함수
function clearHistory() {
    localStorage.clear();
    location.reload();
}
