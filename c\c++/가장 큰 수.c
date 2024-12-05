/*

자연수는 홀수와 짝수로 나눌 수 있다.

10
개의 자연수가 주어질 때, 홀수들 중 가장 큰 수와 짝수들 중 가장 큰 수를 구하여 출력하는 프로그램을 작성하시오. (단 모든 수가 홀수 혹은 짝수라면 가장 큰 수만 출력한다.)


입력
10개의 자연수를 차례대로 입력한다. (단, 10개의 자연수는 모두 1000이하이다.)


출력
가장 큰 홀수 하나와 짝수 하나를 출력한다. 단 홀수 혹은 짝수만 존재할 경우에는 가장 큰 수를 출력한다.


*/



#include<stdio.h>
int main(){
    int solo=0,cup=0,a[11];
    for(int i = 1; i <= 10; i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0 && a[i] > cup){
            cup = a[i];
        }
        else if(a[i] % 2 == 1 && a[i] > solo){
            solo = a[i];
        }
    }
    if(solo == 0){
        printf("%d",cup);
        return 0;
    }
    if(cup == 0){
        printf("%d",solo);
        return 0;
    }
    printf("%d %d",solo,cup);
    return 0;
}
