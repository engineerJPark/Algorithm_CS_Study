// 구간 합을 구하는데 좋은 알고리즘 중 하나이다.
// O(N)의 시간복잡도. 이마저도 비효율적이라 생각하는 알고리즘에 미친자들...
// 결국 트리를 이용해서 시간복잡도를 O(logN)으로 축소시킨다.

#include <stdio.h>
#define NUMBER 7 // data의 개수

int a[] = {7,1,9,5,6,4,1};
int tree[4*NUMBER]; // 4를 곱해서 모든 범위를 커버한다...라고 하는데 그냥 높이를 곱한 것.

// start : 시작하는 인덱스, end : 끝나는 인덱스
// node : 사실 그냥 1이 들어간다...만은 원래는 특정 노드에 특정 값이 들어가게 하기 위해 따로 파라미터로 내놓는다. 즉, 재귀함수로 사용하기 위해 존재하는 파라미터. main에서의 용도는 root node를 지정해주는 것.
int init(int start, int end, int node){
	if(start == end) return tree[node] = a[start]; // 트리의 최하단부까지 내려갔을 때
	int mid = (start + end)/2;
	// 재귀적으로 두 부분으로 나눈 후 그 합을 자기 자신으로 합니다.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start : 시작하는 인덱스, end : 끝나는 인덱스
// left, right : 구간합을 구하고자 하는 범위의 끝 부분
int sum(int start, int end, int node, int left, int right){
	if(left > end || right < start) return 0; // 범위 밖
	if(left <= start && end <= right) return tree[node]; // 범위 안
	// left == start, end == right인 상황이 아니라면, 두 부분으로 나눠 합을 구한다.
	int mid = (start + end)/2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start : 시작하는 인덱스, end : 끝 인덱스
// index : a[]에서 구간 합을 수정하고자 하는 노드. node는 tree 관련 파라미터이다.
// dif : 이만큼 더한다.
void update(int start, int end, int node, int index, int dif){
	if(index < start || index > end) return; // 수정하고자 하는 숫자가 범위 밖에 있는 경우.
	
	tree[node] += dif; // 범위 안에 있으면 내려가면서 다른 원소도 갱신한다.
	if(start == end) return;
	int mid = (start + end)/2;
	update(start, mid, node * 2, index, dif); update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(){
	// 구간 합 트리의 인덱스를 제외하면 모든 인덱스가 0부터 시작한다.
	init(0, NUMBER - 1, 1); // 구간 합 트리 생성하기
	printf("0 to 6 : %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	printf("3 to 6 : %d\n", sum(0, NUMBER - 1, 1, 3, 6));
	
	printf("+3 to element of index 5\n");
	update(0, NUMBER - 1, 1, 5, 3);
	
	printf("0 to 6 : %d\n", sum(0, NUMBER - 1, 1, 0, 6));
	printf("3 to 6 : %d\n", sum(0, NUMBER - 1, 1, 3, 6));
	
	return 0;
}