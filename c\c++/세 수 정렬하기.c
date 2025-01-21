/*

세 수를 오름차순으로 정렬하려고 한다. (낮은 숫자 -> 높은 숫자)

예)

5 8 2   ====> 2 5 8    로 출력



입력
세 정수가 입력된다.



출력
낮은 숫자 부터 출력한다.



*/



#include<stdio.h>
int main(){
    int a[100], small, point, TMP;
    for(int i=1; i<=3; i++){
        scanf("%d",&a[i]);
    }
    for(int i=1; i<=3; i++){
        small = a[i];
        point = i;
        for(int j=i; j<=3; j++){
            if(small > a[j]){
                small = a[j];
                point = j;
            }
        }
        TMP = a[i];
        a[i] = a[point];
        a[point] = TMP;
    }
    for(int i = 1; i <= 3; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
