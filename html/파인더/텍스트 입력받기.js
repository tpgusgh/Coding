
let text1 = document.getElementById('text1').value;
let text2 = document.getElementById('text2').value;
function escapeHtml(text) {
    const map = {
        '&': '&amp;',
        '<': '&lt;',
        '>': '&gt;',
        '"': '&quot;',
        "'": '&#039;'
    };
    return text.replace(/[&<>"']/g, function(m) { return map[m]; });
}
document.getElementById('bttn').addEventListener('click', function(){
    const nav = document.getElementById('nav');
    nav.classList.toggle('active');
    this.classList.toggle('active');
});

function answer(){
    const text1 = document.getElementById('text1').value;
    const text2 = document.getElementById('text2').value;
    if (!text2){
        alert("단어를 입력해주세요.");
        return;
    }
    else{
        innerText = "";
        const escapedText = escapeHtml(text1);
        const regex = new RegExp(`(${text2})`, 'gi'); // 입력된 단어를 대소문자 구분 없이(gi 플래그 사용) 찾기 위해 정규 표현식을 사용
        if (!regex.test(text1)) {
            document.getElementById('outputtext').innerText = "밑줄이 하나도 없습니다.";
            return;
        }
        const highlightedText= text1.replace(regex, '<span class="highlight">$1</span>');
        document.getElementById('outputtext').innerHTML = highlightedText;
        
    }
}
function save(){
    const text1 = document.getElementById('text1').value;
    const text2 = document.getElementById('text2').value;
    const escapedText = escapeHtml(text1);
    const regex = new RegExp(`(${text2})`, 'gi');
        localStorage.setItem('text1', text1);
        localStorage.setItem('text2', text2);
        location.href='기록.html'
}

function instagram(){
    window.open('https://www.instagram.com/hyu.2se');
}


function money(){
    window.open('돈.html');
}

function rule(){
    var rule = document.getElementById('rule');
    rule.style.display = 'block';
}

function xx(){
    var rule = document.getElementById('rule');
    rule.style.display = 'none';
}