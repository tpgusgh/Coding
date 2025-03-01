/*

프로그래밍 문제를 풀다 보면 뒤죽박죽인 N개의 데이터를 숫자의 크기 순으로 0 ~ N-1까지의 숫자로 재정렬 해야되는 경우가 종종 있다.

예를 들어 N=5 이고,

50 23 54 24 123

이라는 데이터가 있다면,

2 0 3 1 4

가 된다.

데이터를 재정렬하는 프로그램을 작성하시오



*/






#include<stdio.h>
int check[500001];
int main(){
    int MAX=0,input[500001],a,count=0;
    scanf("%d",&a);
    for(int i = 1; i <= a; i++){
        scanf("%d",&input[i]);
        if(MAX<input[i]){
            MAX = input[i];
        }
        check[input[i]]++;
    }
    for(int i = 1; i <= MAX; i++){
        if(check[i] >= 1){
            check[i] = count;
            count++;
        }
    }
    for(int i = 1; i <= a; i++){
        printf("%d ",check[input[i]]);
    }
    return 0;
}
