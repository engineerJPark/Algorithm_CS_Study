//https://wodonggun.github.io/wodonggun.github.io/algorithm/%EC%A4%91%EC%9C%84%ED%91%9C%EA%B8%B0%EB%B2%95-%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EB%B2%95.html
//중위표기법 to 후위표기법 공부하기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF	99999999

typedef struct {	//stack 구현에 필요한 NODE
	int data[100];
	struct Node *next;
} Node;

typedef struct {	//stack 그자체
	Node *top;
} Stack;


void push(Stack *stack, char* data){
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char* getTop(Stack *stack){
	Node *top = stack->top;
	return top->data;
}

char* pop(Stack *stack){//top 위치에서 데이터 하나를 쏙 빼간다
	if(stack->top == NULL){
		printf("stack underflow\n");
		return -INF;
	}
	Node *node = stack->top;	//선언
	char* data = (char*)malloc(sizeof(char) * 100);//하나의 노드에 들어있는 data의 offset이 100이므로 100을 곱한다.
	strcpy(data, node->data);//data에 문자열 복사
	stack->top = node->next;	//다음걸로 top 바꾸기
	free(node);
	return data;
}

// 중위 표기법 to 후위 표기법
// 1. 피연산자 바로 출력
// 2. 연산자 : 자신보다 우선순위 높거나 같은 것을 제외(은 출력), 자신을 스택에 푸시
// 3. 여는 괄호 ( : 스택에 푸시
// 4. 닫는 괄호 ) : ( 만날때까지 스택에서 팝
// 그리고 스택에 남은 연산자를 모조리 출력한다.

int getPriority(char* i){	//우선순위 함수
	if(!strcmp(i, "(")) {return 0;}
	if(!strcmp(i, "+") || !strcmp(i, "-")) {return 1;}
	if(!strcmp(i, "*") || !strcmp(i, "/")) {return 2;}
	return 3;
}


//이 함수의 stack은 연산자와 괄호를 임시 저장하는 역할이다.
//s는 문자를 담는 이중 포인터, 37 + 5가 "37" "+" "5"로 들어오게 할 것이다.
//즉 주소들의 배열로 만든다.
//size는 들어오는 각 문자의 개수 - 공백으로 센다.
char * transition(Stack *stack, char ** s, int size){
	char res[1000] = {};//후위표기법의 결과물
    char *resptr = res;//이걸 넣어서 해결했다... 배열 그대로 리턴하면 NULL로 리턴된다. 왜지? 컴파일러 문젠가?
	for(int i = 0; i<size; i++){
		//조건문 시작
		if(!strcmp(s[i],"+") || !strcmp(s[i],"-") || !strcmp(s[i],"*") || !strcmp(s[i],"/")){//연산자가 들어왔을 때
			while(stack -> top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])){
				strcat(res, pop(stack));//자신보다 우선순위 높은 경우, pop/print.
				strcat(res, " ");//앞선 연산자를 처리해줘야하기 때문이다.
			}
			push(stack, s[i]);	//우선순위보다 높든 낮든 자신을 스택에 넣음
		}
		else if (!strcmp(s[i], "(")) {push(stack, s[i]);}	//(는 스택에 담아 연산자를 보관하는 역할
		else if (!strcmp(s[i], ")")) { 
			while (strcmp(getTop(stack), "(")) { 
				strcat(res, pop(stack)); strcat(res, " ");//)가 나오면 (가 나올때까지 스택에서 pop한다.
			}//보관한 연산자를 꺼내는 역할이다.
			pop(stack);
		}
		else {strcat(res, s[i]); strcat(res, " ");}	//숫자는 바로 입력시킨다.
		//조건문 끝
	}
	while(stack->top != NULL){	// 나머지 연산자를 res에 붙이는 과정
		strcat(res, pop(stack));
		strcat(res, " ");
	}
	return resptr;
}

//후위 표기법에 대한 연산 함수
void calculate(Stack *stack, char** s, int size){
	int x,y,z;
	for (int i =0; i < size; i++){
		if(!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){
			x = atoi(pop(stack));//연산자가 나오면 앞선 숫자 두개를 꺼낸다.
			y = atoi(pop(stack));
			if(!strcmp(s[i], "+")) z = y + x;
			if(!strcmp(s[i], "-")) z = y - x;
			if(!strcmp(s[i], "*")) z = y * x;
			if(!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);	//z값 buffer에 문자열로서 저장
			push(stack, buffer);	//연산 결과 buffer를 stack에 push
		}
		else{push(stack, s[i]);}	//숫자는 stack에 push
	}//반복하면 연산결과가 나온다.
	printf("%s\n", pop(stack));
}

//https://dojang.io/mod/page/view.php?id=317
//포인터에 메모리 할당 헷갈리면 볼 것
//malloc은 힙의 할당해주는 메모리의 0 offset의 주소를 반환한다.
//그걸 받고 바로 * 연산하면 힙의 메모리를 역참조한다 이말.
int main(void){
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for(int i =0; i < strlen(a); i++){//공백 개수 세면 size가 나온다.
		if(a[i] == ' ') size++;
	}
	char *ptr = strtok(a, " ");	//공백 기준으로 잘라낸 앞부분 연산자/숫자
	char **input = (char**)malloc(sizeof(char*) * size);//주소를 저장하는 배열을 만들려고 이중포인터 선언
	for(int i = 0; i<size; i++){						//size 개수만큼의 길이의 배열이 필요하므로 *size
		input[i] = (char*)malloc(sizeof(char)*100);//주소를 저장하는 배열.주어진 크기는 의미 없음
	}
	for(int i = 0; i<size; i++){
		strcpy(input[i], ptr);//ptr을 input으로 복사  
		ptr = strtok(NULL, " ");//다음 복사할 것 얻어옴. NULL은 하던거 마저 한다는 뜻이다. 왜인지 괄호와 연산자는 잘리지가 않는다...
	}
	char b[1000] = {};//후위표기방식이 저장될 string
    char* res ;
    res = transition(&stack, input, size);    //이부분이 에러다. 대체 왜 res가 NULL이 되는 건가
	strcpy(b, res);   
	printf("후위 표기법 %s\n", b);


	////////////////////////////////////
	size = 1;
	for (int i =0; i < strlen(b) -1 ; i++){
		if(b[i] == ' ') size++;	//후위표기 결과 size 재측정. 괄호가 사라졌으므로
	}
	char *ptr2 = strtok(b, " ");
	for(int i = 0; i<size; i++){
		strcpy(input[i], ptr2);//어차피 size변수로 길이 제한해줄거라 input새로 할당할 필요 없음.
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
	
	
	return 0;
}
