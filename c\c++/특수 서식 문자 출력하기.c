/*
다음 문장을 출력하시오.

special characters
[\n,\",\\] is very important.




입력
입력은 없다.



출력
 해당 문장을 출력한다.

역 슬래시(＼) 는 원(₩) 기호는 같습니다.

한글 글꼴을 사용하는 우리 나라에서는 역슬래시(＼) 키를 누르면 원(₩) 기호가 출력됩니다.

즉, 출력되는 문장의 역슬래시 자리에 원 기호를 사용하시면 됩니다.



*/


#include<stdio.h>
int main(){
    char a[] = "special characters [\\n,\\\",\\\\] is very important.";
    printf("%s\n", a);
    return 0;
}