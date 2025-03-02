<?php
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo '왜지.. MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
?>
<form method=post action=check_go.php>
<input type="text" name=password>
<input type=submit value=확인 style="color: white; background-color: black;">
</form>