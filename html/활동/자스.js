document.addEventListener("DOMContentLoaded", function() {
    const button = document.getElementById('heading');
    const colors = ["red", "blue", "green", "yellow", "purple", "orange","pink"];
    let colorIndex = 0;

    button.addEventListener('click', function() {
        // 버튼의 색깔을 변경
        button.style.color = colors[colorIndex];
        
        // 다음 색깔로 인덱스 업데이트
        colorIndex = (colorIndex + 1) % colors.length;
    });
});