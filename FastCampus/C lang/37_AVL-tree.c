// 균형인수 = |왼쪽자식높이 - 오른쪽 자식 높이|가 2이상일 때 문제가 있다고 판단
// AVL트리는 모든 노드에 대한 균형 인수가 1,0,-1이다. 균형이 갖춰진 이진트리이다. O(logN)의 시간복잡도
// 완전이진트리에 가까운 형태를 유지하도록 해준다.
// AVL트리는 균형인수를 계산하기 위해 자신의 높이값을 가지고 있어야한다.
// 위 세가지에 해당 안된다면 회전을 통해 트리를 재구성해야한다.
	
// 4가지 형식에 의해 균형이깨진다.
// LL,LR,RR,RL형식 : X의 '왼쪽' 자식의 '왼쪽'에 삽입하는 경우...

#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b)
{
	if(a > b) return a;
	return b;
}

typedef struct{
	int data;
	int height;		//높이를 저장해야 시간 복잡도를 보장
	struct Node * leftChild;
	struct Node * rightChild;
} Node;

Node * root = NULL;

int getHeight(Node * node)
{
	if(node == NULL) return 0;
	return node->height;
}

//회전 후 높이 다시 계산할 때 사용
void setHeight(Node * node){
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference(Node * node){
	if(node == NULL) return 0;
	Node * leftChild = node->leftChild;
	Node * rightChild = node->rightChild;
	return getHeight(leftChild) - getHeight(rightChild);
}

//LL회전 순서
//X의 leftChild가 원래 leftChild의 rightChild가 되게한다.
//leftChild의 rightChild가 X가 되게한다.
Node * rotateLL(Node * node){
	Node * leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산
	return leftChild; //leftChild는 이후 setHeight() 수행
}

//RR회전 순서(LL회전과 좌우 대칭)
//X의 rightChild가 원래 rightChild의 leftChild가 되게한다.
//rightChild의 leftChild가 X가 되게한다.
Node * rotateRR(Node * node)
{
	Node * rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산	
	return rightChild; //rightChild는 이후 setHeight() 수행
}

//RR회전하고 LL회전 시전
Node * rotateLR(Node * node)
{
	Node * leftChild = node->leftChild;	
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node); //leftChild는 이후 setHeight() 수행
}

//LL회전하고 RR회전 시전
Node * rotateRL(Node * node)
{
	Node * rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node); //leftChild는 이후 setHeight() 수행
}


Node * balance(Node * node)
{
	int difference = getDifference(node);
	if(difference >= 2){
		if(getDifference(node->leftChild) >= 1){//leftChild의 leftChild가 더 클 때
			   node = rotateLL(node);
		}
		else{
			   node = rotateLR(node);	//이외의 경우는 무조건 LR인 경우이기 때문에
		}
    }
	else if(difference <= -2)
	{
		if(getDifference(node->rightChild) <= -1){//rightChild의 rightChild가 더 클 때
			node = rotateRR(node);
		}
		else{
			node = rotateRL(node);//이외의 경우는 무조건 RL인 경우이기 때문에
		}
	}
	setHeight(node);	//회전 이후에 높이를 다시 계산한다.
	return node;
}

//삽입은 전시간의 이진트리 처럼 왼쪽이 우선이다.
//삽입할 때마다 가장 아래 노드부터 위까지 balance해주면 된다.
Node * insertNode(Node * node, int data)
{
	if(!node)//최초 노드 생성
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;		//기존 이진트리와 다른 점
		node->leftChild = node->rightChild = NULL;
	}
	else if(data < node->data)	//입력<루트노드 데이터
	{
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);		//기존 이진트리와 다른 점
	}
	else if(data > node->data)	//입력>루트노드 데이터
	{
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);		//기존 이진트리와 다른 점
	}
	else{
		printf("데이터 중복\n");
	}
	return node; 
}

void display(Node * node, int level){	//여기서 level이 높이를 말하는 것이다.
	if(node != NULL){
		display(node->rightChild, level + 1);	//가장 큰 것부터(오른쪽 자식부터) 출력하겠단 의지.
		printf("\n");
		if(node == root){
			printf("Root : ");
		}
		for(int i = 0; i < level && node != root; i++){
			printf("        ");	//가장 깊은 노드가 가장 오른쪽에 출력되도록 한다.
		}
		printf("%d(%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

		   
int main(void){
	root = insertNode(root, 7);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 9);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	root = insertNode(root, 16);
	root = insertNode(root, 18);
	root = insertNode(root, 23);
	root = insertNode(root, 21);
	root = insertNode(root, 14);
	root = insertNode(root, 15);
	root = insertNode(root, 19);
	root = insertNode(root, 20);
	
	display(root, 1); printf("\n");
	
	return 0;
}

// 1) 편향이진트리(Skewed Binary Tree)의경우탐색에있어𝑂(𝑁)의시간복잡도를가집니다.
// 2) 따라서AVL트리를이용하여탐색에있어서𝑂(𝑙𝑜𝑔𝑁)의 시간복잡도를유지할수있습니다