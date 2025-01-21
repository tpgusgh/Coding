/*
n이 입력되면 
n×123456789의 결과를 출력하시오.

이 문제는 다음 키워드를 사용하지 못한다.


입력
정수 n이 입력된다.(0<=n<=100)

출력
n×123456789의 결과를 출력한다.


*/



#include<stdio.h>
int main(){
    unsigned int a;
    scanf("%u",&a);
    printf("%llu",a*123456789ULL);
    return 0;
}
