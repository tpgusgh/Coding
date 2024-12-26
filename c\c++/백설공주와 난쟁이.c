/*

문제1) 백설공주와 난쟁이 (초등1)

안개 숲에는 백설 공주와 7명의 난쟁이가 함께 살고 있다.

7명의 난쟁이의 키가 입력으로 주어질때 이 중 키가 가장 큰 난쟁이와 두 번째로 큰 난쟁이의 키를 출력하는 프로그램을 작성하시오.



입력
첫 째 줄부터 일곱 번째 줄까지 한 줄에 하나씩 난쟁이의 키가 주어진다. 주어지는 난쟁이의 키는 100보다 작은 자연수이다.


출력
첫째 줄에는 가장 키가 큰 난쟁이의 키를 출력한다. 두 번째로 키가 큰 난쟁이의 키를 출력한다.

만약 가장 키가 큰 난쟁이가 둘 이상이라면 첫째 줄과 둘째 줄에 같은 값을 출력해야 한다.

*/



#include<stdio.h>
int nan[8];
int main(){
    int num,fristbig=0, secondbig=0;
    for(int i = 1; i <= 7; i++){
        scanf("%d",&nan[i]);
        if(nan[i] > fristbig){
            num = i;
            fristbig = nan[i];
        }
    }
    for(int i = 1; i <= 7; i++){
        if(nan[i] > secondbig && num != i){
            secondbig = nan[i];
        }
    }
    printf("%d\n%d",fristbig,secondbig);
    return 0;
}
