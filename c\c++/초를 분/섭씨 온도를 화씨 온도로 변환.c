/*


섭씨 온도가 입력되면 화씨 온도로 변환하시오.

화씨 온도 = 9 / 5 * 섭씨온도 + 32


입력
섭씨 온도가 입력된다. (정수)


출력
화씨온도를 소수 셋째자리 까지 출력한다. (실수)



*/




#include<stdio.h>
int main(void){
    int a;
    float result;
    scanf("%d",&a);
    result = (float) 9/5*a+32;
    printf("%0.3f",result);
    return 0;
}
//9 / 5 * 섭씨온도 + 32
