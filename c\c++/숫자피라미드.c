/*
길이 
n
이 입력되면 다음과 같은 숫자 피라미드를 출력한다.

예)

n
이 5이면

1

1 2

1 2 3

1 2 3 4

1 2 3 4 5

입력
길이 n이 입력된다.(1<=n<=99)


출력
숫자 피라미드를 출력한다.

(출력되는 숫자 사이는 빈 칸으로 띄운다.)
*/

#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        for(int j=1; j<=i; j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}