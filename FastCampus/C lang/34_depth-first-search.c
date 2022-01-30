//스택, 재귀함수를 쓰면 간단히 구현가능
//흔히 말하는 DFS가 이거다.

//아래 예제는 방문순서에 대한 명시는 없다. 하지만 알고리즘 상 늦게 입력된 것이 먼저 출력된다.

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1001

typedef struct
{
	int index;
	struct Node * next;
} Node;

Node ** a;
int n, m; //c의 용도 : 방문 체크
int c[MAX_SIZE] ={0};

void addFront(Node * root, int index) //앞을 계속 추가
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x)
{
	if(c[x]) return;	//중단 조건
	
	c[x] = 1;
	printf("%d ", x);
	Node * cur = a[x]->next;	//맨처음 루프의 경우
	//addFront에 의해 a[x]->next부터가 index가 들어있는 실제 데이터이다.
	
	while(cur != NULL)	//스택이 아니라 재귀함수 방식으로 구현했다.
	{
		int next = cur->index;
		dfs(next);	//한번 재귀함수 들어가면 바닥까지 뜷고 간다... 학습 자료 참고
		cur = cur->next;
	}
	//해당 cur에 여러 개의 노드가 연결되어있으면 다른 방향의 노드로 이동하게 된다.
	//아닌 경우 cur에 NULL이 들어가면서 멈춘다.
}

int main(void)
{
	//연결리스트 초기화 부분
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * MAX_SIZE);
	
	//연결리스트 초기화 부분
	for(int i = 1; i <= n; i++)
	{
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	
	//트리간 연결 지정. 서로 지정하게 만든다.
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}//a[i]별로 각각의 연결리스트를 만들어서 서로의 연결관계를 저장하게 된다.
	
	dfs(1);
	
	return 0;
}

//아니 이것도 메모리 해제를 안해주냐...