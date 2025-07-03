let random = 0;
        var audio = new Audio('뚱이소리.mp3');
        var audio2 = new Audio('에반게리온.mp3');
        let answer = document.getElementById("answer");
        let start = document.getElementById("start");
        let restart = document.getElementById("restart");
        let time = 5;
        let text = document.getElementById("text");
        var img = document.createElement('img');
        var img2 = document.createElement('img');
        img2.src = '람.jpeg'
        img.src = '렘짱.jpeg'; 
        var result =  Math.floor(Math.random() * 101 );
        start.onclick = function(){
            if(Number(answer.value) == ''){   //Number 숫자로받기
                alert('뭐라도 써라' + ' ' + '기회: ' + time);
            }
            else if(Number(answer.value) == result){
                alert('정답');
                document.getElementById('imageContainer2').appendChild(img);
                img.style.display = 'block';
                yoo.style.display = 'block';
                start.disabled = false;
                answer.value = '';
                audio2.play();
            }
            else if(Number(answer.value) > result){
                time--; //횟수 차감
                alert('DOWN!!' + ' ' + '기회: ' + time);
                
            }
            else if(Number(answer.value) < result){
                time--;
                alert('UP!!' + ' ' + '기회: ' + time);
                
            }
            time.ineerHTML = "time";
            if (time === 0) {
                alert('게임 오버');
                alert('정답:' + result);
                start.disabled = true;
                document.getElementById('imageContainer').appendChild(img2); //id에 이벤트 
                img2.style.display = 'block'; //사진 나타나기
                yoo2.style.display = 'block'; //글 나타나기
                audio.play(); //소리출력
            }
            }
        restart.onclick = function() {
            result = Math.floor(Math.random() * 100);  //랜덤값 다시지정(1~100) 
            start.disabled = false;  //스타트버튼막기
            answer.value = '';  //
            alert('리셋');  
            time = 5;
            document.getElementById('yoo').style.display = 'none'; //텍스트 숨기기
            document.getElementById('yoo2').style.display = 'none'; //텍스트 숨기기
            img.style.display = 'none'; //이미지 숨기기
            img2.style.display = 'none'; //이미지 숨기기
        }



