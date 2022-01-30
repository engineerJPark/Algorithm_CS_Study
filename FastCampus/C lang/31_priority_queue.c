// 우선순위 큐 : 우선순위가 높은 데이터가 가장 먼저 나온다.
// O(logN)의 시간 복잡도
// 운영체제 등에서 자주 쓴다 카더라
// 우선순위 큐는 트리 구조로 보는 것이 옳다. 최대 힙을 이용한다.

// 최대힙 : 부모노드가 자식 노드보다 값이 큰 완전 이진 트리
// 전체트리가 최대 힙 구조를 유지하도록 자료구조를 설계한다.
// Push, Pop으로 구성한다.

// 위에서 왼쪽부터 차례로 인덱스 설정

#include <stdio.h>
#define MAX_SIZE 10000

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//heap은 인덱스, count는 원소의 개수
typedef struct
{
	int heap[MAX_SIZE];
	int count;
} priorityQueue;

void push(priorityQueue * pq, int data)
{
	if(pq->count >= MAX_SIZE) return;
	//이진트리 마지막 부분에 data가 들어간다. now는 push된 데이터의 인덱스
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count -1)/2; // 이 부분은 그냥 공식이다.
	//새 원소 삽입 후 상향식으로 힙을 구성
	while(now > 0 && (pq->heap[now])>(pq->heap[parent]))
	{
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1)/2;
	}
	pq->count++;	
}

int pop(priorityQueue * pq)
{
	if(pq->count <= 0) return -9999;
	
	int res = pq->heap[0]; //추출할 원소
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	
	int now = 0, leftChild = 1, rightChild = 2; //인덱스
	int target = now;
	
	//새원소 추출 후 하향식 구성
	while(leftChild < pq->count)
	{
		if(pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
		if(target == now) break; //더이상 내려가지 않아도 될때
		else
		{
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftChild = now*2+1;
			rightChild = now*2+2;
		}
	}
	return res;
}

void main()
{
	int n, data;
	scanf("%d", &n);
	priorityQueue pq;
	pq.count = 0;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		push(&pq, data);
	}
	for(int i = 0; i < n; i++)
	{
		int data = pop(&pq);
		printf("%d ", data);
	}
	
	return;
}

//참고
//https://gmlwjd9405.github.io/2018/05/10/algorithm-heap-sort.html