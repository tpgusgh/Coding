/*

printf()함수를 공부하는 진영이는 다음 폴더명을 출력해보기로 했다.

"c:\test"
printf함수에는 특별한 제어문자가 몇개 있다.

큰따옴표(")를 출력하기 위해선 \" 를 사용해야 하고,

\를 출력하기 위해선 \\ 를 사용해야 한다.

입력
입력 없음
출력
"c:\test"

*/

#include<stdio.h>
int main(void){
    printf("\"c\:\\test\"");
}