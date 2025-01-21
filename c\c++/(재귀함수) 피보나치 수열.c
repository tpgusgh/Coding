/*


피보나치 수열이란 앞의 두 수를 더하여 나오는 수열이다.

첫 번째 수와 두 번째 수는 모두 1이고, 세 번째 수부터는 이전의 두 수를 더하여 나타낸다. 피보나치 수열을 나열해 보면 다음과 같다.

 

1, 1, 2, 3, 5, 8, 13 …

 

자연수 N을 입력받아 N번째 피보나치 수를 출력하는 프로그램을 작성하시오.

※ 이 문제는 반드시 재귀함수를 이용하여 작성 해야한다.



입력
자연수 N이 입력된다. (N은 20보다 같거나 작다.)



출력
N번째 피보나치 수를 출력한다.

*/



#include <stdio.h>

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d",fibonacci(N));

    return 0;
}


