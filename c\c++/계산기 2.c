/*


계산기 1에서 두 피연산자에 대한 연산만 다루었다.

이번에는 식을 입력하면 차례대로 계산하여 출력하는 계산기를 만들어보자.

단, 우선순위는 따지지 않고 왼쪽에서 부터 차례대로 계산하고, 모든 계산은 정수형 계산으로 처리한다.



입력

첫째 줄에 정수와 사칙연산기호가 식으로 입력된다.

(정수는 int 범위, 괄호 없이 +,-,*,/) 

식의 마지막엔 =가 입력된다.



출력
왼쪽부터 차례대로 연산한 결과를 출력한다.(우선순위x)



*/




#include <stdio.h>
char s[1000];

int main() {
    int i = 0, sum = 0, num = 0;
    char op = '+';

    scanf("%s", s);

    while (s[i] != '=') {
        if (s[i] >= '0' && s[i] <= '9') {
            num = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            if (op == '+') sum += num;
            else if (op == '-') sum -= num;
            else if (op == '*') sum *= num;
            else if (op == '/') {
                if (num == 0) {
                    return 1;
                }
                sum /= num;
            }
        } else {
            op = s[i];
            i++;
        }
    }

    printf("%d\n", sum);
    return 0;
}
