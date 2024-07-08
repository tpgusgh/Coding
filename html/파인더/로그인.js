function login() {
    const id = document.getElementById('id').value;
    const password = document.getElementById('password').value;
    if (id === 'kimhyunhi' && password === 'bssm1234') {
        alert('김현호님 환영합니다.')
        location.href = '텍스트 입력받기.html';
    } else {
        alert('아이디 또는 비밀번호가 잘못되었습니다.');
    }
}