/*
세 수 를 입력받아 세 수의 최대공약수를 구하는 프로그램을 작성하시오.


입력
첫째 줄에 세 수 가 주어진다.(단,1 <= a <= b <= c <= 100,000 )

출력
출력내용은 세 수 의 최대공약수를 출력한다.
*/





#include<stdio.h>
int main(){
    int a,b,c,s;
    scanf("%d %d %d",&a,&b,&c);
    while(b){
        s = a % b;
        a = b;
        b = s;
    }
    while(a){
        s = c % a;
        c = a;
        a = s;
    }
    printf("%d",c);
}
