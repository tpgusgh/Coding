/*


정수 하나를 입력받아 양수이면 "양수", 음수이면 "음수", 0이면 0을 출력하시오.




입력
정수 하나가 입력된다.



출력
양수이면 "양수", 음수이면 "음수", 0이면 0을 출력하시오.



*/





#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a>=1){
        printf("양수");
    }
    else if(a == 0 ){
        printf("0");
    }
    else{
        printf("음수");
    }
}
