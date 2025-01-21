/*

두 실수 a, b가 입력되면 그 두수를 더하거나 빼거나 곱하거나 나누거나 제곱을 해서 가장 큰 수를 출력하시오.

예를 들어 1과 2가 입력되면,

1+2 = 3   , 2+1 = 3

1 - 2 = -1,   2 - 1 = 1

1 * 2 = 2,    2 * 1 = 2

1 / 2 = 0.5,   2 / 1 = 2

12=1 ,   21 = 2

따라서 최댓값은 3이다.



입력
실수 a, b가 입력된다. ( a와 b의 계산결과는 모두 int범위 이내이고, 계산이 불가능한 경우는 입력되지 않는다.)




출력
최댓값을 소수점이하 6자리로 출력한다.



*/



#include<stdio.h>
#include<math.h>
int main(){
    float a,b,q,w,e,t,r,battle1,battle2,max;
    scanf("%f %f",&a,&b);
    if(a+b > b+a) q = a+b;
    else q = b+a;
    if(a-b > b-a) w = a-b;
    else w = b-a;
    if(a*b > b*a) e = a*b;
    else e = b*a;
    if(a/b > b/a) r = a/b;
    else r = b/a;
    if(pow(a,b) > pow(b,a)) t = pow(a,b);
    else t = pow(b,a);
    if(q > w) battle1 = q;
    else battle1 = w;
    if(e > r) battle2 = e;
    else battle2 = r;
    if(battle1 > battle2) max = battle1;
    else max = battle2;
    if(max > t) printf("%0.6f",max);
    else printf("%0.6f", t);
    return 0;
}
