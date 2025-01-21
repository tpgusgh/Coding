/*

n이 입력되면 다음과 같은 삼각형을 출력하시오.

예)n이 5이면
*
**
***
****
*****


입력
길이 n이 입력된다.(1<=n<=150)


출력
삼각형을 출력한다.
*/




#include<stdio.h>
int a;
int b=1;
int c=1;
int f(){
    if(a==c){
        printf("*");
        return 0;
    }
    else if(b==c){
        printf("*\n");
        b++;
        c=1;
        return f(c);
    }
    else if(b>c){
        printf("*");
        c++;
        return f(c);
    }
    return 0;
}

int main(void){
    scanf("%d",&a);
    f(a);
    return 0;
}