function login() {
    const id = document.getElementById('id').value;
    const password = document.getElementById('password').value;
    if (id === 'minorpiece' && password === '1234') {
        alert('마이너피스님 환영합니다.')
        localStorage.setItem('loged-in', 1);
        location.href = 'write.html';
    } else {
        alert('아이디 또는 비밀번호가 잘못되었습니다.');
        localStorage.setItem('loged-in', 0);
    }
}