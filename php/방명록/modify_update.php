<?php
    $conn = mysqli_connect('localhost', 'root', '', 'mydb');
    if(mysqli_connect_errno()){
        echo 'MYSQL 접속 실패 : ' .mysqli_connect_error();
        exit();
    }
    $query = "update myuser set name='".$_POST['myname']."',
    age=".$_POST['myage'].",
    gender='".$_POST['mygender']."',
    work='".$_POST['mywork']."'
    where num=".$_POST['mynum'].";";
    $result = mysqli_query($conn, $query);

    if($result){
        echo "<script>alert('데이터 수정 성공!!!!!')</script>";
    }
    else{
        echo "<script>alert('실패 ㅋ')</script>";
    }
?>
<meta http-equiv="refresh" content="0; url=view.php">


