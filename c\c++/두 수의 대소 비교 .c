/*


두 정수가 입력된다.  두 정수의 크기를 비교하여 왼쪽 수가 크면 > 를 출력, 오른쪽 수가 크면 < 를 출력, 같으면 = 을 출력하시오.




입력
두 정수 a, b가 입력된다.



출력
a가 b보다 크면  > 를 출력,

b가 a보다 크면  < 를 출력,

a와 b가 같으면  = 를 출력한다.


*/



#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b){
        printf(">");
    }
    else if(a<b){
        printf("<");
    }
    else{
        printf("=");
    }
    return 0;
}
