#include<stdio.h>
#include<stdlib.h>

//tree struct
typedef struct
{
	int data;
	struct Node * leftChild;
	struct Node * rightChild;
} Node;

Node * insertNode(Node * root, int data)
{
	if(root == NULL)//맨 처음 data input
	{
		root = (Node *)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else
	{
		if(root->data > data)
		{
			root->leftChild = insertNode(root->leftChild, data);
		}
		else
		{
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

Node * searchNode(Node * root, int data)
{
	if(root == NULL) return NULL;
	if(root->data == data) return root;
	
	else if(root->data > data) return searchNode(root->leftChild, data);
	else return searchNode(root->rightChild, data);
}

//순회
void preorder(Node * root)
{
	if(root == NULL) return;
	
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

//가장 작은 원소 찾기
Node * findMinNode(Node * root)
{
	Node * node = root;
	while(node->leftChild != NULL)
	{
		node = node->leftChild;
	}
	return node;
}

Node * deleteNode(Node * root, int data)
{
	Node * node = NULL;
	if(root == NULL) return NULL;
	if(root->data > data) root->leftChild = deleteNode(root->leftChild, data);
	else if(root->data < data) root->rightChild = deleteNode(root->rightChild, data);
	else //삭제할 원소 찾았다.
	{
		if(root->leftChild != NULL && root->rightChild != NULL)//자식노드가 2개인 경우
		{
			node = findMinNode(root->rightChild);//오른쪽에서 가장 작은거
			root->data = node->data;
			root->rightChild = deleteNode(root->rightChild, node->data);	//원래 있던 오른쪽에서 가장 작은거 제거
		}
		else //자식이 하나이거나 아예 없는 경우. 자식이 하나만 있으면 무조건 왼쪽에 있으므로
		{
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
			free(root);
			return node;
		}
	}
	
	return root;
}



int main()
{
	Node * root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	
	preorder(root);
	printf("\n");
	printf("finding 50: %d", (searchNode(root, 50))->data);
	
	printf("\n");
	deleteNode(root, 30);
	preorder(root);
		
	return 0;
}

//완전이진탐색 트리가 되도록 만들어야한다.
//트리 효율성 : O(N)공간 소요, 탐색에 O(logn)
//편향이진트리가 되는경우 O(N)의 시간복잡도가 형성되므로, AVL이진트리를 도입한다.