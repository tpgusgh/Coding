/*

SuperSum
함수는 다음과 같이 정의된다.
SuperSum(0,n)=n(n은  모든 양의 정수)SuperSum(k,n)=SuperSum(k−1,1)+SuperSum(k−1,2)+...+SuperSum(k−1,n)k와 n이 여러개 주어진다. Su
perSum의 값을 각각 출력하시오.


입력
k(1<=k<=14)와 n(1<=n<=14)이 입력된다. 입력의 끝은EOF(End Of File)이다.

입력 처리 방법)

while( scanf("%d %d", &k, &n) != EOF )
	printf("%d\n", SuperSum(k, n));

출력
SuperSum(k,n)의 값을 각 행에 하나씩 출력한다.
*/


#include<stdio.h>

int SuperSum(int a, int b){
    int num[15][15]={0};
    for(int i=1; i<=14; i++){
        for(int j=1; j<=14; j++){
            if(i-1==0){
                for(int p=1; p<=j; p++){
                    num[i][j]+=p;
                }
            }
            else{
                for(int p=1; p<=j; p++){
                    num[i][j] += num[i-1][p];
                }
            }
        }
    }
    return num[a][b];
}

int main(void){
    int k,n,i;
    while( scanf("%d %d", &k, &n) != EOF )
    printf("%d\n", SuperSum(k, n));
}