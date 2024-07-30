/*

당신은 웹사이트 제작자이다.

ID를 입력하고 엔터를 누르면 환영 메시지를 띄우려고한다.

예를 들어 ID가 anaki인 경우, welcome! anaki를 출력한다.

환영 메시지를 출력하는 프로그램을 작성하시오.


입력
ID를 입력한다.(ID는 10글자 미만 영문자이다.공백없음)


출력
welcome! ID 형태로 출력한다.


*/

#include <stdio.h>

int main() {
    char a[100];  
    scanf("%s", a);  
    printf("welcome! %s", a); 
    return 0;
}