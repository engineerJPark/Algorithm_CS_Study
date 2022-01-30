//강의자료 참고
//이진트리는 많은 양의 노드를 낮은 높이에서 관리할 수 있다.
//데이터 저장 및 탐색 등에 활용가능

#include<stdio.h>
#include<stdlib.h>

typedef struct  
{
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
} Node;

Node * initNode(int data, Node * leftChild, Node * rightChild)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	
	return node;
}

//이진 트리 데이터 방문 방법을 순회라고 한다.
// 1. 전위순회 : 자기자신-왼쪽-오른쪽 방문

void preorder(Node * root){
	if(root)//NULL만 아니면 된다.
	{
		printf("%d ", root->data);
		preorder(root->leftChild);//왼쪽 다 방문하면 오른쪽 방문
		preorder(root->rightChild);
	}
}

//2. 중위순회 : 왼쪽 - 자기자신 - 오른쪽. 왼쪽부터 차례로 방문하게 된다.
void inorder(Node * root){
	if(root)//NULL만 아니면 된다.
	{
		inorder(root->leftChild);//왼쪽 끝까지 방문한다.
		printf("%d ", root->data);
		inorder(root->rightChild);
	}
}

//3. 후위순회 : 왼쪽 - 오른쪽 - 자기자신. 루트가 가장 마지막에 출력된다.

void postorder(Node * root){
	if(root)//NULL만 아니면 된다.
	{
		postorder(root->leftChild);//왼쪽 끝까지 방문한다.
		postorder(root->rightChild);
		printf("%d ", root->data);
	}
}

int main(void)
{
	Node * n7 = initNode(50, NULL, NULL);
	Node * n6 = initNode(37, NULL, NULL);
	Node * n5 = initNode(23, NULL, NULL);
	Node * n4 = initNode(5, NULL, NULL);
	Node * n3 = initNode(48, n6, n7);
	Node * n2 = initNode(17, n4, n5);
	Node * n1 = initNode(30, n2, n3);
	
	preorder(n1);
	printf("\n");
	
	inorder(n1);
	printf("\n");
	
	postorder(n1);
	printf("\n");
	
	return 0;
}
