/*

어떤 문자열이 있을 때 문자 t의 위치를 모두 찾아 출력하시오.


출력
공백이 없는 문자열이 한 줄 입력된다.(10글자 이하)


입력
소문자 t의 위치를 공백으로 분리하여 모두 출력하시오.

*/

#include<stdio.h>
int main(){
    char a[100];
    scanf("%s",&a);
    for(int i=0; i<=100; i++){
        if(a[i] == 116){
            printf("%d ",i+1);
        }
    }
    return 0;
}