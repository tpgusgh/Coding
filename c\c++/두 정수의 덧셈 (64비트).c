/*


두 정수의 덧셈의 결과를 출력한다.

두 수는 int 범위를 넘어선 64비트 정수형 값이다.



입력
두 정수 a, b가 입력된다. (-263 <= a+b <= 263-1)


출력
두 정수의 합을 출력한다.


*/



#include<stdio.h>
int main(){
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",a+b);
    return 0;
}
