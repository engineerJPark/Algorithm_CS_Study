#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
#define INF 99999999

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct Queue{//queue에 대한 정보를 저장한다.
	Node *front;
	Node *rear;
	int count;
} Queue;

void push(Queue *queue, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(queue->count == 0){
		queue->front = node;
	}
	else{
		queue->rear->next = node;//맨뒤에 추가
	}
	queue->rear = node;
	queue->count++;
}

int pop(Queue *queue){
	if(queue->count == 0){
		printf("queue underflow");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	
	return data;
}

void show(Queue *queue){
	Node *cur = queue->front;
	printf("---front---\n");
	while(cur != NULL){
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---rear---");
}

// int main(void) {
// 	Queue queue;
// 	queue.front = queue.rear = NULL;
// 	queue.count = 0;
	
// 	push(&queue, 7);
// 	push(&queue, 5);
// 	push(&queue, 4);
// 	pop(&queue);
// 	push(&queue, 6);
// 	pop(&queue);
// 	show(&queue);
	
// 	return 0;
// }

int main(void) {
	Queue *queue = (Queue*)malloc(sizeof(Queue));	//*queue의 주소만 저장하고 실체인 *queue는 행방불명이므로 동적할당을 해줘야한다.
	queue->front = queue->rear = NULL;
	queue->count = 0;
	
	push(queue, 7);
	push(queue, 5);
	push(queue, 4);
	pop(queue);
	push(queue, 6);
	pop(queue);
	show(queue);

	free(queue);
	return 0;
}
