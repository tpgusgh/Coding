<?php
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $result = mysqli_query($conn, $query);
    if(0905 != $_POST['password']){
        echo '<script>';
        echo "alert('비밀번호가 맞지않습니다.');";
        echo 'history.back();';
        echo '</script>';
    }
?>