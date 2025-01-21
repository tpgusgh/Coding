<?php
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = "select * from myuser where num = ".$_GET['num'].";";
    $result = mysqli_query($conn, $query);
    $count = mysqli_num_rows($result);
    if($count == 0){
        echo "조회된 값 없음";
    }
    else{
        $row = mysqli_fetch_assoc($result);
    }




?>






<html>
    <h3>수정이 페이지</h3>
    <body>
        <form method=post action=modify_update.php>
        이름: <input type=text name=myname value=<?php echo $row['name']; ?>><br>
        나이: <input type=text name=myage value=<?php echo $row['age'];?>><br>
        성별: <input type=text name=mygender value=<?php echo $row['gender'];?>><br>
        직업: <input type=text name=mywork value=<?php echo $row['work']; ?>><br>
        <input type=hidden name=mynum value=<?php echo $_GET['num']; ?>>
        <input type=submit value='확인'>
        </form>
    
    </body>

</html>

