// 모든간선이방향을가지는그래프를방향그래프라고 합니다.
// 모든간선에가중치가 있는그래프를가중치그래프라고 합니다.
// 무방향비가중치그래프가 주어졌을때연결되어있는상황을인접리스트로출력할수있습니다.

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int index;
	int distance;
	struct Node * next;
} Node;

void addFront(Node * root, int index, int distance) //앞을 계속 추가
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node * root)
{
	Node * cur = root->next;
	while(cur != NULL)
	{
		printf("%d(거리 : %d)", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	Node ** a = (Node**)malloc(sizeof(Node*) * (n+1));
	for(int i = 1; i <= n; i++)//행별로 초기화...
	{
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	
	for(int i = 0; i < m; i++)
	{
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);
	}
	
	for(int i = 1; i <= n; i++)
	{
		printf("원소 [%d] : ", i);
		showAll(a[i]);
		printf("\n");
	}
	
	return 0;
}

//근데 메모리 해제는 안해주냐????? 누수 오지누...