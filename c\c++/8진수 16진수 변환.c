/*



10진수 정수를 입력받아 8진수와 16진수로 출력한다.




입력
10진수 정수 하나가 입력된다.



출력
8진수와 16진수를 차례대로 출력한다.

(16진수는 대문자 출력)



*/





#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    printf("%o %X",a,a);
    return 0;
}