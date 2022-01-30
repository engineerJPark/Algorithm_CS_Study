// 구조체와 포인터 이용해서
// 중간지점에 노드 추가 삭제
// 메모리 할당을 받아야 사용가능

//단일 연결 리스트

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct Node* next_node;
}Node;

Node* head;


void addBehind(Node* root, int data){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node -> data = data;
	new_node -> next_node = root -> next_node;
	root -> next_node = new_node;
}

void deleteBehind(Node* root){
	Node* behind = root -> next_node;
	root -> next_node = behind -> next_node;
	free(behind);
}

void freeList(){
	Node* cur_node;
	cur_node = head -> next_node;
	Node* next_cur_node;
	while(cur_node != NULL){
		next_cur_node = cur_node -> next_node;
		free(cur_node);
		cur_node = next_cur_node;
	}
	free(head);
}

void show(){
	Node* cur_node;
	cur_node = head -> next_node;
	
	while(cur_node != NULL){
		printf("%d ", cur_node->data);
		cur_node = cur_node -> next_node;
	}
	printf("\n");
}

int main(){
	head = (Node*)malloc(sizeof(Node));
	head -> next_node = NULL;
	addBehind(head, 1);
	addBehind(head, 2);
	addBehind(head, 3);
	show();
	
	deleteBehind(head);
	show();
	
	freeList();
	return 0;	
}