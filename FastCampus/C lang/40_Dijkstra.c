// 1) 다익스트라의 최단 경로(Dijkstra‘s Shortest Path Algorithm)는 매우 잘 알려진 알고리즘입니다.
// 2) 각 간선에 대한 정보를 우선순위 큐에 담아 처리하는 방식으로 동작 원리가 프림 알고리즘과 흡사합니다.
// 3) 현실 세계에서는 음의 간선이 존재하지 않기 때문에 다익스트라는 현실 세계에 적합한 알고리즘입니다.

// 프림 알고리즘과의 차이점은 간선의 '가중치'가 아닌 간선의 '이동거리'를 중심으로 판단한다는 점이다.
// 즉 기존 이동했던 노드를 거쳐간다는 가정하에 '이동거리'를 계산하고 이를 통해 Table을 갱신한다.

// 기존의 테이블을 매번 새로 갱신하는 특징이 있다.
// 거리 = 현재 노드까지 이동한 거리 + 현 노드로부터의 거리
// 우선순위 큐를 이용해서 구현한다.

// 프림알고리즘과 매우매우 흡사. main 함수에서 차이가 난다.

// 프림 알고리즘과 같이 시간복잡도 O(ElogV)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 600001 // 양방향 간선이므로 300000개를 고려


// Node가 Edge를 참조, priorityQueue가 Edge의 cost를 중심으로 최소값이 pop되게 구성.
// 간선의 정보를 담는 구조체
typedef struct {
	int cost; //가중치값
	int node; //연결된 노드 번호
} Edge;

// 간선에 대한 정보를 우선순위 큐로 담는다는 것이다.
// cost가 낮은 간선을 빠르게 찾을 수 있게
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
int ans[NODE_MAX]; // ans는 시작 노드에서 특정 노드까지의 최단 거리값을 의미한다.
					// 프림 알고리즘은 트리에 포함된 노드인지 구분하기 위해 d라는 변수를 사용했다.

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
	int n, m, k; // n은 node 개수, m은 간선 개수, k는 시작할 노드의 번호
	scanf("%d %d %d", &n, &m, &k);
	adj = (Node**)malloc(sizeof(Node*)*(n+1)); 
	for(int i = 1; i <= n; i++){ // 모든 노드를 초기화한다.
		adj[i] = NULL;
		ans[i] = INT_MAX;
	}
	priorityQueue * pq; //우선순위 큐 초기화
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	//a, b, c는 각각 연결된 노드 인덱스1, 연결된 노드 인덱스2, 움직임에 따른 코스트
	for(int i = 0; i < m; i++){ // 각 간선 정보 기록
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
	// Dijkstra Algorithm start
	ans[k] = 0; // 시작 노드는 거리가 0이어야하니깐
	Edge *start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0; start->node = 1; push(pq, start);
	
	while(1){
		Edge * now = pop(pq);
		if(now == NULL) break; // 큐에서 다 뽑았단 뜻
		int curNode = now->node;
		int curCost = now->cost;
		
		// 1. ans[curNode]가 INT_MAX인 것을 고치겠단 의미
		// 2. 최단 경로를 찾아서 TABLE을 갱신한다는 의미
		// 새로 찾은 경로(curCost)가 기존 경로 ans보다 작아야 갱신
		if(ans[curNode] < curCost) continue; 
		Node * cur = adj[curNode];
		while(cur != NULL){
			Edge * temp = cur->data;
			temp->cost += curCost;
			if(temp->cost < ans[temp->node]){ ans[temp->node] = temp->cost; push(pq, temp); }
			cur = cur->next;
		}
	}
	for(int i = 1; i <= n; i++){ // 시작 노드에서 특정 노드까지의 최단 거리값을 Table 형태로 모두 출력
		if(ans[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", ans[i]);
	}
	
	return 0;
}