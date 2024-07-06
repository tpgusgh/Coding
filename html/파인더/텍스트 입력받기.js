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
        document.getElementById('outputtext').innerText = "단어를 입력해주세요.";
        return;
    }
    else{
        innerText = "";
        const escapedText = escapeHtml(text1);
        const regex = new RegExp(`(${text2})`, 'gi'); // 입력된 단어를 대소문자 구분 없이(gi 플래그 사용) 찾기 위해 정규 표현식을 사용
        if (!regex.test(text1)) {
            alert("밑줄이 하나도 없습니다");
            document.getElementById('outputtext').innerHTML = "";
            return;
        }
        const highlightedText= text1.replace(regex, '<span class="highlight">$1</span>');
        document.getElementById('outputtext').innerHTML = highlightedText;
        const data = 'data';

        const userInfo = {
            id: "아이디",
            name: "이름",
            password: "비밀번호",
          }
          
          const aTag = document.querySelector('a');
          aTag.addEventListener('click', () => {
            localStorage.setItem("user-info", JSON.stringify(userInfo));
          });
    }
}