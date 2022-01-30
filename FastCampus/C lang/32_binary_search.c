// 이진 탐색(Binary Search)는 한 번 확인할 때마다 보아야 하는 원소의 개수가 절반씩 줄어든다는 점에서 탐색 시간에 서 𝑂(𝑙𝑜𝑔𝑁)의 시간 복잡도를 가집니다.
// 정렬이 되어있다는 가정하에 사용한다.
// 1) 순차탐색은𝑂(𝑁)의 시간 복잡도를 가집니다.
//2) 이진탐색은정렬이된상태에서만사용가능하며𝑂(𝑙𝑜𝑔𝑁)의 시간 복잡도를 가집니다.

#include<stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

//start, end는 index이다. mid도 index
int search(int start, int end, int target)
{
	if(start > end){return -9999;}
	int mid = (start + end)/2;
	
	if(a[mid] == target) return mid; 
	else if(a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}

int main()
{
	int n, target;
	scanf("%d %d", &n, &target);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int result = search(0, n-1, target);
	if(result !=-9999) printf("%d번째 원소이다.\n", result + 1);
	else printf("not found\n");
	
	return 0;
}