/*

첫 줄에 데이터의 개수 N(N은 홀수)이 입력되고, 그 다음 줄에 N개의 데이터가 입력된다.

여기서 첫번째 데이터, 중간 데이터, 마지막 데이터를 출력하시오.

예) 

5

2 4 6 1 7

이면

2 6 7

이 출력된다.

(첫번째 데이터 2,

중간 데이터 6,

마지막 데이터 7)


입력
입력으로 N이 주어지고 그 다음줄에 N개의 데이터가 공백으로 구분되어 입력된다.(단, N>=1인 홀수)


출력
첫번째, 중간, 마지막 데이터 값을 출력한다.




*/


#include<stdio.h>
int input[100];
int main(){
    int pan;
    scanf("%d",&pan);
    for(int i = 1; i <= pan; i++){
        scanf("%d",&input[i]);
    }
    printf("%d ",input[1]);
    if(pan % 2 == 1){
        printf("%d ",input[ pan/2 +1]);
    }
    else{
        printf("%d ",input[pan/2]);
    }
    printf("%d",input[pan]);
    return 0;
}
