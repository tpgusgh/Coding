/*

배열에서 가장 큰 값이 처음 나타나는 위치를 출력하시오.

단, 함수형 문제이므로 함수 f()만 작성하시오.

[함수형 문제란??]
함수형 문제는 기본적인 main() 등은 미리 작성되어 있습니다.
미리 작성되어 있는 프로그램은 다음과 같습니다.



입력 
첫 줄에 데이터의 개수 n이 입력된다.

두 번째 줄에 n개의 데이터가 공백을 두고 입력된다.

출력
가장 큰 값이 처음 나타나는 위치를 출력한다.



*/



#include <stdio.h>

int n, d[110];



int f(){
    int i,big;
    for(i=1; i<n; i++){
        big=d[big]<d[i]?i:big;
    }
    return big+1;
}
int main()
{
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", &d[i]);

  printf("%d", f());
  return 0;
}
