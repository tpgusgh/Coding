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
        const highlightedText= text1.replace(regex, '<span class="highlight">$1</span>');
        document.getElementById('outputtext').innerHTML = highlightedText;
    }
}