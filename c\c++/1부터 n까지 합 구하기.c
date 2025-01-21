/*

정수 n이 입력으로 들어오면 1부터 n까지의 합을 구하시오.



입력
입력으로 자연수 n이 입력된다. (1<=n<=10,000)

출력
1부터 n까지의 합을 출력한다.
*/


#include<stdio.h>
int sum=0;
void f(int b){
    sum += b;
    b--;
    if(b==0){
        printf("%d",sum);
        return;
    }
    else{
        f(b);
    }
}
int main(){
    int a;
    scanf("%d",&a);
    f(a);
    return 0;
}