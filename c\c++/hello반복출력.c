/*

hello라는 글자를 n번 반복 출력하는 프로그램을 작성하시오.

예를 들어 n이 5가 입력되면, hello를 5줄에 걸쳐 출력한다.


출력
입력으로 정수 n이 입력된다.(1<=n<=100)

입력
hello를 n줄에 걸쳐서 출력한다.
*/


#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        printf("hello\n");
    }
    return 0;
}