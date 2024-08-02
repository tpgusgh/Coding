/*


시작수(a)와 마지막 수(b)가 입력되면

a부터 b까지의 모든 홀수를 출력하시오.

입력
두 수 a, b 가 입력된다. (1<=a<=b<=100)


출력
a~b의 홀수를 모두 출력한다.


*/



#include<stdio.h>
int a, b;
void f(){
    if(a % 2 == 1){
        printf("%d ", a);
    }
    a++;
    if(a != b){
        f();
    }
    return;
}
int main(void){
    scanf("%d %d", &a, &b);
    b++;
    f();
    return 0;
}
