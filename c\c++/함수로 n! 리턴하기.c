/*

int 형 정수 한 개를 입력 받아
n!(팩토리얼)을 계산해 출력하시오.
(0 <= n <= 20)

n!(팩토리얼)은 1부터 n까지 모두 곱한 수를 의미한다. 
5! 은 1*2*3*4*5 = 120 이다.


입력
int 형 정수(n)가 입력된다.
출력
n! 값을 출력한다.



*/

#include <stdio.h>

int n;




int f(int n){
    int i,c=1;
    for(i=1; i<=n; i++){
        c=c*i;
    }
    return c;
}
int main()
{
  scanf("%d", &n);
  printf("%lld\n", f(n));
}

