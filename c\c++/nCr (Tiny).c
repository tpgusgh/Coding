/*

nCr은 n개의 원소를 가지는 집합에서 
r개의 부분 집합을 고르는 조합의 수를 말한다.
nCr을 일반 공식은 다음과 같다.
nCr=nPrr!=n!r!⋅(n−r)!5C2는 다음과 같이 구할 수 있다.
5C2=5!3!×2!=5×4×3×2×1(3×2×1)×(2×1)=10nCr을 구하는 프로그램을 작성하시오.


*/

#include<stdio.h>
#include<stdlib.h>

int f(int n, int r){
    if(r == n) return 1;
    if(r == 1) return n;
    return f( n - 1, r - 1) +f(n - 1, r);
}


int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d", f(n,r));
    return 0;
}


/*

#include<stdio.h>
#include<stdlib.h>
int memo[15][15];
int f(int n, int r){
    if(memo[n][r]) return memo[n][r];
    if(r == n) return memo[n][r] = 1;
    if(r == 1) return memo[n][r] = n;
    return memo[n][r] = f( n - 1, r - 1) +f(n - 1, r);
}


int main(){
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d",f(n,r));
    return 0;
}


*/