/*

*주의사항 : 이 (함수 제출형) 문제는 함수 부분만 작성해서 제출해야 오류 없이 채점이 됩니다.
미리 작성되어있는 코드를 읽고 해석해서, 함수 부분만 작성해서 제출하면 됩니다.
작성한 함수의 테스트를 위해서는 제시된 코드를 복사해 사용하면 되고, 제출은 함수 부분만 하세요.

------

n 개의 정수를 배열로 입력 받고, 
원하는 값 k가 저장되어있는 가장 처음 위치를 출력하시오.
(원하는 값 k값이 저장되어있지 않은 경우에는 –1을 출력한다.)

단, 함수형 문제이므로 함수 f()만 작성하시오.


[함수형 문제란??]
함수형 문제는 기본적인 main() 등은 미리 작성되어 있습니다.
미리 작성되어 있는 프로그램은 다음과 같습니다.

미리 작성된 프로그램을 복사해 붙여 넣은 후 함수 부분을 설계하여 작성해 넣고,
테스트 한 후, 함수 부분만 제출하세요.


입력
첫 줄에 데이터의 개수 n,
두 번째 줄에 n개의 데이터가 공백을 두고 입력된다.
세 번째 줄에 찾아야하는 값 k가 입력된다.
(1 <= n <= 100000)
(-2147483648 <= k <= 2147483647)


출력
k값이 가장 처음 나타나는 위치를 출력한다.
(k값이 저장되어있지 않은 경우에는 –1을 출력한다.)

*/



#include <stdio.h>

int n, d[100010], k;




int f(int j){
    for(int i = 1; i <= n; i++){
        if(j == d[i]){
            return i;
        }
    }
    return -1;
}
int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    scanf("%d", &d[i]);

  scanf("%d", &k);
  printf("%d\n", f(k));
}

