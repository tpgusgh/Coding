/*

scanf("%s", str);를 사용하면 공백이후의 문자를 입력받지 못한다.

공백이 있는 문자열을 입력받아 출력해보자.



입력
공백이 포함된 문자열이 입력된다. (최대길이 30)

출력
입력받은 문자열을 그대로 출력한다.






*/





#include<stdio.h>
int main(){
    char a[1000];
    gets(a);
    printf("%s",a);
    return 0;
    
}
