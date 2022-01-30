// 신장 트리 : 모든 정점을 포함하는 그래프
// 최소신장트리 : 스패닝 트리 중 간선 가중치 합이 가장 작은 트리

// 1) 그래프에서 정점 하나를 선택하여 트리 T에 포함시킵니다.
// 2) T에 포함된 노드와 T에 포함되지 않은 노드 사이의 간선 중에서 가중치가 가장 작은 간선을 찾습니다.
// 3) 해당 간선에 연결된 T에 포함되지 않은 노드를 트리 T에 포함시킵니다.
// 4) 모든 노드가 포함될 때까지 2)와 3) 과정을 반복합니다.

// 중요한 것은 간선을 중심으로 노드를 트리에 포함시킨다는 점이다.
// 간선이 연결된 모든 노드를 포함하는 데에 필요한 최소 가중치를 구하는 것이 목적이다.

// 각 노드의 간선들 중 가장 코스트가 적은 간선만 선택
// 인접한 노드 들 중... 트리 T와 연결안된 간선 중에서 가장 작은 것들만 포함시키겠다.
// 우선순위 큐에 담아 처리한다.
// 프림 알고리즘은 최소 스패닝 트리를 구하는 과정에서 O(ElogV) 시간복잡도

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001 // 양방향 간선이므로 100000개를 고려


// Node가 Edge를 참조, priorityQueue가 Edge의 cost를 중심으로 최소값이 pop되게 구성.
// 간선의 정보를 담는 구조체
typedef struct {
	int cost; //가중치값
	int node; //연결된 노드 번호
} Edge;

// 간선에 대한 정보를 우선순위 큐로 담는다는 것이다.
// cost가 낮은 것을 빠르게 찾을 수 있게
typedef struct {
	Edge *heap[EDGE_MAX]; // edge의 주소를 받는다
	int count;
} priorityQueue;

typedef struct Node {
	Edge * data; //간선의 주소
	struct Node * next;
} Node;

void swap(Edge *a, Edge *b){ //우선순위 큐 참고
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

void push(priorityQueue *pq, Edge *edge) { //우선순위 큐 참고
	if(pq->count >= EDGE_MAX) return; //예외처리 : 용량 초과
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count -1)/2;
	//새원소 삽입 후 상향식 힙 구성
	while (now > 0 && (pq->heap[now]->cost) < (pq->heap[parent]->cost)) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent -1)/2;
	}
	pq->count++;
}

Edge * pop(priorityQueue *pq) { //우선순위 큐 참고
	if(pq->count <= 0) return NULL; //예외처리
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	
	// 원소 추출 후 하향식 힙 구성
	while(leftChild < pq->count){
		if(pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if(pq->heap[target]->cost > pq->heap[rightChild]->cost) target = rightChild;
		if(target == now) break; // 더 이상 내려가지 않아도 되면 종료
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1; // 공식이다.
			leftChild = now * 2 + 2; // 공식이다.
		}
	}
	return res;
}

Node ** adj; //각 인덱스가 각 노드의 번호이다. 노드의 인접 간선에 관한 정보를 넘기기 위한 변수
int d[NODE_MAX]; //이미 최소신장트리에 포함시킨 노드인지 확인하는 용도

void addNode(Node ** target, int index, Edge * edge) {
	if (target[index] == NULL){ //아무것도 없는 경우...
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else { // 한 노드에 관한 인접 간선 정보 스택 쌓기
		Node * node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

int main(){
	int n, m; //n은 node의 개수, m은 간선의 개수
	scanf("%d %d", &n, &m);
	adj = (Node**)malloc(sizeof(Node*)*(n+1)); 
	for(int i = 1; i <= n; i++){ // 모든 노드를 초기화한다.
		adj[i] = NULL;
	}
	priorityQueue * pq; //우선순위 큐 초기화
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	//a, b, c는 각각 연결된 노드 인덱스1, 연결된 노드 인덱스2, 움직임에 따른 코스트
	for(int i = 0; i < m; i++){
		int a, b, c; 
		scanf("%d %d %d", &a, &b, &c); 
		//양방향으로 기록해준다.
		Edge *edge1 = (Edge*)malloc(sizeof(Edge));
		edge1->node = b;
		edge1->cost = c;
		addNode(adj, a, edge1);
		Edge *edge2 = (Edge*)malloc(sizeof(Edge));
		edge2->node = a;
		edge2->cost = c;
		addNode(adj, b, edge2);
	}
	// Prim's Algorithm start
	long long res = 0; //8바이트용 정수형
	Edge *start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0;
	start->node = 1;
	push(pq, start);
	// Prim's Algorithm - 최소신장 트리 구성부
	for(int i = 1; i <= n; i++){
		int nextNode = -1, nextCost = INT_MAX;
		while(1){
			Edge * now = pop(pq); //pop되는 위치가 최소값이 나오게 만들어놨다..
			if(now == NULL) break;
			nextNode = now->node;
			if(!d[nextNode]){
				nextCost = now->cost;
				break;
			}
		}
		if(nextCost == INT_MAX) printf("it's not connected graph...\n");
		res += nextCost;
		d[nextNode] = 1;
		Node * cur = adj[nextNode]; // cur->data는 edge에 관한 정보이다.
		while(cur != NULL){ push(pq, cur->data); cur = cur->next; } //노드에 인접한 모든 간선 정보 투입
	}
	printf("%lld\n", res); // 간선 가중치 총합을 뱉는다
	
	return 0;
}