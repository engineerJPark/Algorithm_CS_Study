#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {	//stack 구현에 필요한 NODE
	int data;
	struct Node *next;
} Node;

typedef struct {	//stack 그자체
	Node *top;
} Stack;

void push(Stack *stack, int data){
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack *stack){
	if(stack->top ==NULL){
		printf("stack underflow\n");
		return -INF;
	}
	Node *node = stack->top;	//선언
	int data = node->data;	//선언
	stack->top = node->next;	//다음걸로 top 바꾸기
	free(node);
	return data;
}

void show(Stack *stack){
	Node *cur = stack->top;
	printf("---stack top---\n");
	while(cur != NULL){		//NULL인 곳이 bottom이 되도록 설정하였다.
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---stack bottom---\n");
}

int main(){
	Stack stack;
	stack.top = NULL;
	//
	show(&stack);
	show(&stack);
	push(&stack, 7);
	push(&stack, 5);
	push(&stack, 4);
	pop(&stack);
	push(&stack, 6);
	pop(&stack);
	show(&stack);
	//
	return 0;
}