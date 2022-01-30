//계수 정렬, counting sorting
//데이터의 크기가 한정적일 때 사용한다.
#include<stdio.h>
#define MAX_VALUE 10000

//n is number of elements.
//m is index
int n, m;
//a[MAX_VALUE] contains the number of one kind of elements.
int a[MAX_VALUE];


void main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){ scanf("%d", &m); a[m]++;}
	for(int i=0; i<MAX_VALUE; i++){//MAX_VALUE까지 전부 탐색해야한다.
		while(a[i]!=0){
			printf("%d ", i);
			a[i]--;
		}
	}
}