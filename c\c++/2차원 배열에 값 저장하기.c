/*

n행 m열의 2차원 배열에 값을 저장하고 출력하려고 한다.

첫째 줄에 2차원 배열의 크기 n과 m을 입력받고,각각의 데이터를 2차원 배열에 저장한 다음 그대로 출력하시오.

입력
첫째 줄에 n과 m이 입력된다.(1<=n,m<=100), 각각의 데이터는 int둘째 줄부터 n×m의 데이터가 차례대로 입력된다.


출력
n×m 크기의 2차원 배열을 출력한다.
*/


#include<stdio.h>
int main(){
    int a[100][100],b,c;
    scanf("%d %d",&b,&c);
    for(int i=1; i<=b; i++){
        for(int j=1; j<=c; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1; i<=b; i++){
        for(int j=1; j<=c; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
