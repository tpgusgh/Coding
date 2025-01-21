/*



철수는 정 수 두 개를 입력하면 두 수 사이의 기본 연산이 자동으로 이루어지는 프로그램을 제작하고 싶다.

기본 연산이란, 더하기, 빼기, 곱하기, 나누기, 나머지 연산 등 5가지 연산을 말한다.

두 정수의 기본 연산을 출력하는 정수 계산기를 제작하시오.



입력
두 정수 a, b를 공백으로 분리하여 입력한다.


출력
다음 형식으로 출력한다. c, d, e, f, g에 해당되는 수는 실제 계산 결과를 의미한다.

a + b = c
a – b = d
a * b = e
a / b = f
a % b = g



*/




#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %d\n",a,b,a/b);
    printf("%d %% %d = %d\n",a,b,a%b);
    return 0;
}