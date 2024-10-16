/*


프로그래밍 문제를 풀다 보면 뒤죽박죽인 N개의 데이터를 숫자의 크기 순으로 0 ~ N-1까지의 숫자로 재정렬 해야되는 경우가 종종 있다.

예를 들어 N=5 이고,

50 23 54 24 123

이라는 데이터가 있다면,

2 0 3 1 4

가 된다.

데이터를 재정렬하는 프로그램을 작성하시오.




입력
첫째 줄에 데이터의 개수 N이 입력된다. ( 1 <= N <= 50,000)

둘째 줄에 공백으로 분리되어 N개의 서로 다른 데이터가 입력된다. (값의 범위:0~500,000)



출력
N개의 데이터를 0 ~ N-1로 재정렬하여 출력하라.







*/




#include<stdio.h>

int main() {
    int a, b[100000], c[100000], tmp, p;
    
    scanf("%d", &a);
    
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
        c[i] = b[i];
    }
    
    for (int i = 0; i < a; i++) {
        p = i;
        for (int j = i + 1; j < a; j++) {
            if (b[j] < b[p]) {
                p = j;
            }
        }
        tmp = b[p];
        b[p] = b[i];
        b[i] = tmp;
    }
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (c[i] == b[j]) {
                printf("%d ", j);
                break;
            }
        }
    }
    
    return 0;
}
