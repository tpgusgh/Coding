/*


두 정수 중 큰 정수를 출력한다.


입력
두 정수가 입력된다.

출력
두 정수 중 큰 정수를 출력한다.



*/


#include<stdio.h>
int main(){
    int a,b; 
    scanf("%d %d",&a,&b);
    printf("%d",a > b ? a : b); //삼항연산자 
    return 0;
}