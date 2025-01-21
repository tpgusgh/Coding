
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
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = "select * from myuser;";
    $result = mysqli_query($conn, $query);
    $count = mysqli_num_rows($result);
    echo "<table border=1 width=500 align=center>";
    echo "<tr align=center><td colspan=7>데이터의 갯수는 ".$count."개 입니다</td></tr>";
    echo "<tr><th>번호</th><th>이름</th><th>나이</th><th>성별</th><th>직업</th><th>삭제</th><th>수정</th></tr>";
    
    while($row = mysqli_fetch_assoc($result)){
        
        echo "<tr align=center>
        <td>".$row['num']."</td>
        <td>".$row['name']."</td>
        <td>".$row['age']."</td>
        <td>".$row['gender']."</td>
        <td>".$row['work']."</td>
        <td><a href=delete.php?num=".$row["num"].">삭제</a></td>
        <td><a href=modify.php?num=".$row["num"].">수정</a></td>
        </tr>";
        
    }
    echo "</table>";
?>


<form method=post action=insert.php style="text-align: center">
    <input placeholder="이름" class=input type=text name=username><br>
    <input placeholder="나이" class=input type=text name=age><br>
    <input placeholder="성별" class=input type=text name=gender><br>
    <input placeholder="직업" class=input type=text name=work><br>
    <input type=submit value=저장 style="color: white; background-color: black;">
</form>


