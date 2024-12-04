/*

입력의 개수 n이 입력되고 n개의  데이터가 입력된다.

이 n개의 데이터 중 최댓값을 출력한다.



입력
첫째줄에 정수의 개수 N이 주어진다. (n<=1000)

둘째줄에 N개의 정수가 공백으로 분리되어 주어진다.  ( 0 <= 각각의 데이터 <=1000000 )



출력
N개의 정수 중 최댓값을 찾아 출력한다.



*/



#include<stdio.h>
int main(void){
    int b,MAX=0, a;
    scanf("%d",&b);
    for(int i = 1; i <= b; i++){
        scanf("%d",&a);
        if(a > MAX){
            MAX = a;
        }
    }
    printf("%d",MAX);
    return 0;
}
