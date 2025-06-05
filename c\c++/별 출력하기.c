/*
문제설명
별(*)을 n개 만큼 출력한다.


입력 예시   
5

출력 예시
*****



*/

#include<stdio.h>
int main(){
    int a,i;
    scanf("%d",&a);
    for(i=1; i<=a; i++){
        printf("*");
    }
    return 0;
}
