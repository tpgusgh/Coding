/*

광곽이는 만우절을 맞이하여 아침에 일어나는 학생들을 위해 모든 기상곡 사이에 “AMOLED”를 집어넣으려 한다.

(단, 마지막에는 AMOLED가 오지 않게 한다. 학생들이 싫어한다.)


입력
총 기상곡의 개수 n과 2번째 줄부터 n+1번째 줄까지 현재 기상곡의 목록이 줄바꿈을 사이에 두고 입력된다. (1<=n<=100)
(단, 각 기상곡의 글자 수는 100자 이하이다.)


출력
기상곡과 기상곡 사이에 AMOLED가 삽입되게 한다.
*/

#include<stdio.h>
int main(){
    char a[10000];
    int f,i;
    scanf("%d",&f);
    for(i=1; i<=f; i++){
        scanf("%s",a);
        printf("%s\n",a);
        if(i!=f){
            printf("AMOLED\n");
        }
    }
    return 0;
}
