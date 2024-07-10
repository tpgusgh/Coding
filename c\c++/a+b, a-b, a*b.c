/*

두 정수 a, b에 a+b, a-b, a*b 연산을 적용한다.

이 연산의 결과의 중앙 값을 출력하시오.

중앙 값이란 숫자를 크기 순서로 정렬했을 때, 가장 중앙에 위치한 값을 말한다.



입력
정수 a, b가 공백으로 분리되어 입력된다.(-10,000 <= a, b <=10,000)

출력
연산 결과의 중앙값을 출력한다.


*/


#include<stdio.h>
int main(void){
    int a,b,c,te,tel;
    scanf("%d %d",&te,&tel);
    a = te + tel;
    b = te - tel;
    c = te * tel;
    if(a<b || a<c){
        if(a>b || a>c){
            printf("%d",a);
        }
    }
    if(b<a || b<c){
        if(b>a || b>c){
            printf("%d",b);
        }
    }
    if(c<a || c<b){
        if(c>a || c>b){
            printf("%d",c);
        }
    }
    return 0;
}