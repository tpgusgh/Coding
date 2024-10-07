/*


수의 개수 n이 주어지고, 그 다음 줄에 무작위로 n개의 정수가 입력된다.

그 n개의 수 중에서 홀수의 개수를 출력하시오.



입력
첫 번째 줄에 n이 입력된다.(1<=n<=10,000)

두 번째 줄에 정수가 n개 공백을 기준으로 주어진다.(1<=k<=100)


출력
n개의 수들 중 홀수의 개수를 출력한다.



*/




#include<stdio.h>
int b[1000];
int main(){
    int a , count = 0;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        scanf("%d",&b[i]);
    }
    for(int i=1; i<=a; i++){
        if(b[i] % 2 == 1){
            count++;
        }
    }
    printf("%d",count);
}
