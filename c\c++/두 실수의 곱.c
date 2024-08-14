/*

두 실수를 입력받아 두 실수의 곱을 출력하되 소수 둘째자리까지 출력하시오.


입력
두 실수를 입력받는다.


출력
두 실수의 곱을 소수 둘째자리까지 출력한다.



*/


#include<stdio.h>
int main(){
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%0.2f",a*b);
    return 0;
}
