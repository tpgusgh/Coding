/*


두 정수를 입력받아 아래와 같이 출력하시오.

예)  3 2

3+2=5
3-2=1
3*2=6
3/2=1


입력
두 정수 a, b를 입력받는다.


출력
a와 b에 대한 사칙연산 결과를 양식에 맞추어 출력한다.



*/



#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d+%d=%d\n",a,b,a+b);
    printf("%d-%d=%d\n",a,b,a-b);
    printf("%d*%d=%d\n",a,b,a*b);
    printf("%d/%d=%d\n",a,b,a/b);
    return 0;
}