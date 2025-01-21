/*

A선생님이 연말정산을 하려고 한다. 근로소득공제액은 총급여액에 따라 달라지며, 아래 표의 규칙에 의해서 결정된다.(근로소득공제액은 만원미만은 절사한다.)

총 급여액	근로소득공제액500만원 이하	총 급여액의 100분의 70
500만원 초과 1500만원 이하	350만원 + 500만원 초과하는 금액의 100분의 401500만원 초과 
4500만원 이하	750만원 + 1500만원 초과하는 금액의 100분의 154500만원 초과 
1억원 이하	1200만원 + 4500만원 초과하는 금액의 100분의 5
1억원 초과	1475만원 + 1억원 초과하는 금액의 100분의 2
예를 들어 총급여액이 
3130만원인 경우 750+(3130−1500)∗15/100=994.5가 되므로 근로소득공제액은 994만원이 된다.
근로소득공제액을 구하는 프로그램을 작성하시오.



입력
 첫번째 줄에 총급여액이 입력된다.

총급여액은 20억원 이하로 입력된다. 금액은 만원 단위로 입력된다.

출력
 첫 번째 줄에 근로소득공제액을 출력한다. 금액은 만원 단위까지만 출력한다.



*/




#include<stdio.h>
int main(void){
    int a;
    scanf("%d",&a);
    if(500 >= a){
        a = a *  70 / 100 ;
    }
    else if( 500 < a && 1500 >= a){
        a = 350 + ( a - 500 ) *  40 / 100 ;
    }
    else if(1500 < a && 4500 >= a){
        a = 750 + ( a - 1500 )  *  15 / 100 ;
    }
    else if( 4500 < a && 10000 >= a){
        a = 1200 + ( a - 4500 ) *  5 / 100 ;
    }
    else{
        a = 1475 + ( a - 10000 ) *  2 / 100 ;
    }
    printf("%d",a);
    return 0;
}