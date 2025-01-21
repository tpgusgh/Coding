/*
5개의 정수들의 최댓값과 최솟값을 구하는 프로그램을 작성하라.


입력
5개의 정수가 한 줄에 하나씩 입력된다.(범위 : −1,000,000~ 1,000,000)

출력

첫째줄에 최댓값을 출력한다.

둘째줄에 최솟값을 출력한다.
*/

#include<stdio.h>
int a[100];
int main(){
    int i,big=0,small=1000;
    for(i=1; i<=5; i++){
        scanf("%d",&a[i]);
    }
    big = a[1];
    small = a[1];
    for(i=1; i<=5; i++){
        if(small>a[i]){
            small = a[i];
        }
        if(big < a[i]){
            big = a[i];
        }
    }
    printf("%d\n%d",big,small);
    return 0;
}