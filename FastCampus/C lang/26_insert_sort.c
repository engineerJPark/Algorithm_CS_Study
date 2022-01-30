#include<stdio.h>
#include<limits.h>
#define SIZE 1000

int a[SIZE] = {};

int swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

void selection_sort(int n){

	

}

int main(void){
	int n, min, index;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n - 1 ; i++){//정렬단계
		int j = i;
		while(j >= 0 && a[j] > a[j+1]){//정렬된 곳의 마지막 부분 보다 작은 게 나오면 실행
			swap(&a[j], &a[j + 1]);
			j--;//끝까지 밀어넣겠다는 의지
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d", a[i]);
	}
}