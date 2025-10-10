/*

문제 설명     
임의의 한 정수 
n
을 입력받아서, 
[
1
,
n
]
범위에서 소수의 합을 출력하시오.

입력
정수 
n
이 입력된다.(
0
<
n
<=
10
,
000
)

출력
[
1
,
n
]
범위의 소수의 합을 출력한다.

입력 예시   
10

출력 예시
17

*/



#include<stdio.h>
int main(){
    int a,i,j,plus=0,check=0;
    scanf("%d",&a);
    for(i=2; i<=a; i++){
        check = 0;
        for(j=2; j<i; j++){
            if(i%j == 0){
                check++;
            }
        }
        if(check == 0){
            plus += i;
        }
    }
    printf("%d",plus);
    return 0;
}
