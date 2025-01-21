/*

우리는 숫자를 int나 long long으로 숫자를 처리하였다.

이번엔 그보다 더 큰 숫자를 비교해보자.

최대 100자리의 두 숫자가 입력되면 작은수와 큰 수를 차례대로 출력하시오.


입력
정수 두개가 입력된다.(최대 100자리) - 같은 숫자는 입력되지 않는다.


출력
작은수 큰수 순서로 출력한다.

*/


#include <stdio.h>
#include <string.h>

// 두 숫자를 비교하는 함수
int compare(const char *a, const char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // 길이가 다른 경우, 길이로 비교
    if (len_a < len_b) return -1;
    if (len_a > len_b) return 1;
    
    // 길이가 같으면 사전 순 비교
    return strcmp(a, b);
}

int main() {
    char num1[101], num2[101];
    
    scanf("%100s", num1);
    scanf("%100s", num2);
    
    // 비교 결과에 따라 출력
    int result = compare(num1, num2);
    if (result < 0) {
        printf("%s %s", num1, num2);
    } 
    else if (result > 0) {
        printf("%s %s", num2, num1);
    } 
    return 0;
}
