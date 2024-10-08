/*

배열 (1,1)부터 저장하여 열 우선 출력한다고 가정 했을때 다음 숫자가 저장될  인덱스는?



입력
첫 번째 줄에 배열의 크기 n m이 입력된다. (1<=  n, m <= 100)



출력
n*m 크기의 배열을 설명과 같이 채워 출력한다.



*/




#include<stdio.h>
int arr[201][201]={0};
int main(){
	int i, j, k, n, m, num=1;
	scanf("%d %d",&n, &m);
	k=2;//k= i+j의 값
	//배열의 인덱스 위치에 값을 저장 코드 작성
	for(int y=1; y<=n+m; y++){
		for(i=n; i>=1; i--){
			for(j=1; j<=m; j++){
				if(k == i + j){
					arr[i][j] = num;
					num++;
				}
			}
			
		}
		k++;
	}
	
	for(i=1; i<=n; i++, puts("")){
			for(j=1; j<=m; j++){
				printf("%d ",arr[i][j]);
			}
		
		}
	
	// 배열의 결과를 출력
	
	return 0;
}
