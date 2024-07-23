/*

자연수 n이 입력되면 3의 배수인지 아닌지 판별하시오.




입력
입력은 자연수 n이 주어지며, 범위는 0<n<10^500입니다.

출력
3의 배수이면 1을 출력하고, 아니면 0을 출력한다.
*/

#include<stdio.h>
char a[501];
int main(void){
    int sum=0, i=0;
    scanf("%s",a);
    while(a[i]!=0){
        sum += a[i]-48;
        i++;
    }
    printf("%d",sum%3 == 0 ? 1:0);
    return 0;
}
