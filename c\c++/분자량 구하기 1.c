/*

화학 숙제를 하던 광곽이는 분자량을 구하라는 문제를 보고 귀찮아 한다.

귀찮은 광곽이를 위해서 화학식을 입력하면 분자량을 구해주는 프로그램을 만들어 주자!

화학식은 CxHy의 꼴로 입력된다.

C의 원자량은 12, H의 원자량은 1로 한다.


입력
화학식이 CxHy
 꼴로 입력된다. (1<=x,y<=100)x,y=1인 경우에도 1을 표시한다.

예) C1H1


출력
분자량을 출력한다.


*/


#include <stdio.h>
char a[1000];
int main() {
    int x=1,i=1,sum=0,number=0;
    scanf("%s",a);
    while(a[i]!=72){
        number = number * x;
        number += (a[i]-48);
        i++;
        if(x == 1){
            x = x * 10;
        }
    }
    sum = number * 12;
    number = 0;
    x = 1;
    i++;
    while(a[i]-48 >= 0 && a[i]-48 < 10){
        number = number * x;
        number += (a[i]-48);
        i++;
        if(x == 1){
            x = x * 10;
        }
    }
    sum += number;
    printf("%d",sum);
    return 0;
}