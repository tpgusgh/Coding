<?php
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = " insert into myuser(name, age, gender, work) 
    values('".$_POST['username']."', ".$_POST['age'].",
    '".$_POST['gender']."', '".$_POST['work']."');";
    $result = mysqli_query($conn, $query);
    if($result){
        echo "<script>alert('데이터가 들어갔습니다.');</script>";
    }
    else{
        echo "<script>alert('실패하였습니다.');</script>";
    }
?>

<meta http-equiv="refresh" content="0; url=view.php">






