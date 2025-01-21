/*


영단어 하나가 입력된다.

그 단어가 love이면 I love you. 를 출력하시오.

 

입력
영어 단어 하나가 입력된다.(15글자 이하)



출력
love가 입력되면 I love you.를 출력하시오. 만약 다른 단어가 입력되면 아무것도 출력하지 않는다.




*/



#include<stdio.h>
int main(){
    char c[1000];
    scanf("%s",&c);
    if(c[0] == 'l'){
        if(c[1] == 'o'){
            if(c[2] == 'v'){
                if(c[3] == 'e'){
                    if(c[4] == '\0'){
                        printf("I love you.");
                    }
                }
            }
        }
    }
    return 0;
}