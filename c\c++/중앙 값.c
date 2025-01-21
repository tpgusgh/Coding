/*

중앙값(median)은 어떤 주어진 값들을 정렬했을 때 가장 중앙에 위치하는 값을 의미한다. 예를 들어 1, 2, 100의 세 값이 있을 때, 2가 가장 중앙에 있기 때문에 2가 중앙값이다. 값이 짝수개일 때에는 중앙값이 유일하지 않고 두 개가 될 수도 있다. 이 경우 그 두 값의 평균을 취한다. 예를 들어 1, 10, 90, 200 네 수의 중앙값은 10과 90의 평균인 50이 된다.

 

5개의 자연수가 주어질 때, 중앙값을 찾아내는 프로그램을 작성하시오.

 

예를 들어, 다음의 수에 대하여 중앙값은,

57 34 87 83 47

크기 순서상으로 57이 가운데 있고 이 값이 중앙값이 된다.



입력
1. 5개의 자연수가 공백으로 구분되어 입력된다.

2. 각 정수는 0보다 크고 100보다 작다.

3. 입력되는 수는 모두 다른 수이다.






출력
1. 중앙값을 출력한다.





*/







#include <stdio.h>
int a[10001];
int n, i, j, temp;
int main() {
    for (i=1; i<=5; i++)
        scanf("%d", &a[i]);

    for(i=1; i<5; i++)
    {
        for(j=1; j<5; j++)
            {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("%d\n", a[3]);
    return 0;
}
