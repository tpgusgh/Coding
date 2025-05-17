/*

다음과 같은 n*n 배열 구조를 출력해보자.

입력이 3인 경우 다음과 같이 출력한다.
3 2 1
4 5 6
9 8 7

입력이 5인 경우는 다음과 같이 출력한다.
5 4 3 2 1
6 7 8 9 10
15 14 13 12 11
16 17 18 19 20
25 24 23 22 21

입력이 n인 경우의 2차원 배열을 출력해보자.

*/






#include<stdio.h>
int main(){
    int a, wi = 1, enf = 0, qustn = 0;
    scanf("%d",&a);
    for(int i = 1; i <= a*a; i++){
        if(wi == 1){
            printf("%d ", (i + a - enf -1) - qustn );
            enf++;
            qustn++;
        }
        else{
            printf("%d ", i);
            enf++;
        }
        if(enf == a){
            enf = 0;
            printf("\n");
            if(wi == 1) wi = 0;
            else wi = 1;
            qustn = 0;
        }
    }
    return 0;
}
