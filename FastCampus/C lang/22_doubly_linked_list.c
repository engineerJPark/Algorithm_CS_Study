//양방향 연결 리스트는 앞/뒤 모두에서 접근 가능하다.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head;
Node* tail;

//삽입함수
void insert(int data){
	//삽입할 노드
	Node *node = (Node*) malloc(sizeof(Node));
	node -> data = data;
	//현재 확인하는 노드
	Node *cur;
	cur = head -> next;
	while (cur->data < data && cur != tail){
		cur = cur -> next;
	}
	//삽입 위치 찾은 후 삽입작업
	//node의 앞부분 먼저
	Node *prev = cur -> prev;
	prev -> next = node;
	node -> prev = prev;
	//node의 뒷부분
	cur -> prev = node;
	node -> next = cur;
}

//헤드 바로 다음 노드(제일 작은 값을)를 삭제하는 함수
void removeFront(){
	//삭제할 노드
	Node* node = head -> next;
	//head 다음에 node 다음 리스트가 나오도록 조정
	head -> next = node -> next;
	//node 다음 리스트
	Node* next = node -> next;
	//다음 노드의 앞선 노드를 head로 변경
	next -> prev = head;
	free(node);
}
//더 삭제할 것이 없는 것에 대한 예외처리가 필요

void show(){
	Node* cur = head->next;
	while(cur != tail){
		printf("%d \n", cur -> data);
		cur = cur -> next;
	}
}

int main(){
	//할당 안하면 사용할 수가 없다...
	head = (Node*) malloc(sizeof(Node));
	tail = (Node*) malloc(sizeof(Node));
	head -> next = tail;
	head -> prev = head;
	tail -> next = tail;
	tail -> prev = head;	//이것들 중 하나가 없으면 메모리 참조에 문제가 생겨서 위의 함수들 중에서 segmentaion오류가 발생. NULL값을 지정하게 되기 때문
	
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	
	removeFront();
	show();
	
	return 0;
}