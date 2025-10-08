/*
문제 설명     
어떤 정수 n과 k가 입력되면, nk의 값을 출력하시오.

이 문제는 for, while, goto, pow 명령을 사용할 수 없다.

 

금지 키워드 : for while goto pow **
입력
공백을 기준으로 int 범위의 정수 n과 k가 주어진다. (n은 0이 아닌 정수, k>=0인 정수)

 

출력
nk의 결과를 출력한다.(결과 값은 long long int값 범위이다.)

 

입력 예시   
3 3

출력 예시
27
*/

#include <iostream>
using namespace std;

long long calc(int n, int k) {
    if (k == 0) return 1;                  // n^0 = 1
    long long half = calc(n, k / 2);       // 절반 계산
    if (k % 2 == 0) return half * half;    // 짝수승: (n^(k/2))^2
    else return n * half * half;           // 홀수승: n * (n^(k/2))^2
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << calc(n, k) << '\n';
    return 0;
}
