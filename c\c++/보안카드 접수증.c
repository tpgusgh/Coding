/*

철수는 대기업의 중요한 업무를 처리하는 부서에 근무하게 되었다. 이 기업은 정보 유출을 막기 위해 근무 장소에 들어갈 때 보안 카드로 신분을 확인한다.

  첫 출근을 한 철수는 보안 카드를 등록하기 위해 보안 카드 자동 등록기에 다음과 같은 정보를 입력해야 한다.

이름, 나이, 부서코드, 보안키

  위 정보가 모두 입력되면 기계에서 보안 카드 접수증을 출력해 주는데, 다음과 같이 이름, 나이, 부서코드, 보안키를 순서대로 줄을 바꿔 출력해야 한다.

mark
20
A
3.154
이 출력 프로그램을 작성하시오.


입력
① 첫째 줄에 이름을 입력한다.(영문자 20 문자이내)

② 다음 줄에 나이를 입력한다.(정수)

③ 다음 줄에 부서코드 A, B, C 중 하나를 입력한다.(영문자)

④ 다음 줄에 보안키를 입력한다.(실수)



출력
출력 형식에 맞게 출력한다.




*/



#include <stdio.h>

int main(void) {
    char a[100], d;
    int b;
    float c;

    // 문자열 입력
    scanf("%s", a);
    printf("%s\n", a);

    // 정수 입력
    scanf("%d", &b);
    printf("%d\n", b);

    // 개행 문자 소비
    getchar();

    // 문자 입력
    scanf("%c", &d);
    printf("%c\n", d);

    // 실수 입력
    scanf("%f", &c);
    printf("%g\n", c);

    return 0;
}