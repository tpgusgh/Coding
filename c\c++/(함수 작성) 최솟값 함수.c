/*

이 문제는 최솟값 함수를 구현하는 문제입니다.

다음 조건을 참고해서 함수 본체만 작성해서 제출하시기 바랍니다.

함수명 : mymin
매개 변수(parameter) :정수형(int)2개
반환 형(return type) : 정수형(int)
함수 내용 : 두 정수 중 작은 값을 구하는 함수 구현


입력
이 프로그램은 int범위의 정수 두 개를 입력으로 받습니다.


출력 
mymin 함수를 구현하여 두 정수 중 작은 수를 출력한다. 함수 본체만 작성해서 제출한다.
*/



#include <stdio.h>

int mymin(int a, int b) {
  return a<b?a:b;
}


main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", mymin(a, b));
}
