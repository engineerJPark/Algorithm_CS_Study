//DFS와 마찬가지로 전체 노드 탐색시 사용
//queue 사용

// 1. 탐색시작노드를큐에삽입하고방문처리를합니다.
// 2. 큐에서노드를꺼내해당노드의인접노드중에서방문하지않은노드들을모두큐에삽입하고, 방문처리를합니다.
// 3. 2번의과정을더이상수행할수없을때까지반복합니다.

// 큐STL을 사용하면 개꿀이라 카더라...

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1001
#define INF 99999999

typedef struct
{
	int index;
	struct Node * next;
} Node;

typedef struct{
	Node * front;//맨앞
	Node * rear;//맨뒤
	int count; //queue의 원소 개수
} Queue;

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

void queuePush(Queue * queue, int index)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	
	if(queue->count == 0)
	{
		queue->front = node;
	}
	else
	{
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int queuePop(Queue * queue)
{
	if(queue->count == 0)
	{
		printf("Queue Underflow...");
		return -INF;
	}
	Node * node = queue->front;
	int index = node->index;
	queue->front = node->next; //shifting
	free(node);
	queue->count--;
	
	return index;
}

void bfs(int start)
{
	Queue q;
	q.front = q.rear = NULL;
	q.count = 0;
	
	queuePush(&q, start);
	c[start] = 1; // 갖다온 표시
	
	while(q.count != 0)
	{
		int x = queuePop(&q);
		printf("%d ", x);
		Node * cur = a[x]->next;
		while(cur != NULL)//아직 안간 인접한 모든 노드 큐에 담기
		{
			int next = cur->index;
			if(!c[next])
			{
				queuePush(&q, next);
				c[next] = 1;
			}
			cur = cur->next;
		}
	}
}

int main()
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
	
	bfs(1);
	
	return 0;
}