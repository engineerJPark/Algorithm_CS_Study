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
	
	for(int i = 0; i < n - 1; i++){
		min = INT_MAX;
		for(int j = i; j < n ; j++){//최소값 찾기
			if(min > a[j]){
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);//최소값하고 맨처음 부분 위치 바꾸기
	}
	
	for(int i = 0; i < n; i++){
		printf("%d", a[i]);
	}
}