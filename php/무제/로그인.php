<?php
    $conn = mysqli_connect('localhost', 'root', '', 'login');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = " insert into user(name, age, gender, id, password) values('".$_POST['name']."', ".$_POST['age'].",
    '".$_POST['gender']."', '".$_POST['id']."', '".$_POST['password']."');";
    $result = mysqli_query($conn, $query);
    if($result){
        echo "<script>alert('회원가입이 성공적으로 완료되었습니다.');</script>";
    }
    else{
        echo "<script>alert('다시 시도해주세요.');</script>";
    }
    $count = mysqli_num_rows($result);
?>

<meta http-equiv="refresh" content="0; url=로그인.php">

<!-- php re render -->