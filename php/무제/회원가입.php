
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>입력페이지</title>
    <style>
    body{    
    height: 100vh;
    background: url(짱구.jpeg) no-repeat center;
    background-size: cover;
    }
    .input {
  width: 50%;
  max-width: 140px;
  height: 5px;
  padding: 12px;
  border-radius: 12px;
  border: 1.5px solid lightgrey;
  outline: none;
  transition: all 0.3s cubic-bezier(0.19, 1, 0.22, 1);
  box-shadow: 0px 0px 20px -18px;
}

.input:hover {
  border: 2px solid lightgrey;
  box-shadow: 0px 0px 20px -17px;
}

.input:active {
  transform: scale(0.95);
}

.input:focus {
  border: 2px solid grey;
}
    </style>
</head>
<body> 
</body>
</html>




<?php
    $conn = mysqli_connect('localhost', 'root', '', 'login');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = "select * from user;";
    $result = mysqli_query($conn, $query);
    $count = mysqli_num_rows($result);
?>











<form method=post action=insert.php style="text-align: center">
    <input placeholder="이름" class=input type=text name=name><br>
    <input placeholder="나이" class=input type=text name=age><br>
    <input placeholder="성별" class=input type=text name=gender><br>
    <input placeholder="아이디" class=input type=text name=id><br>
    <input placeholder="비밀번호" class=input type=password name=password><br>
    <input placeholder="전화번호" class=input type=text name=phone><br>
    <input type=submit value=회원가입하기 style="color: white; background-color: black;">
</form>
