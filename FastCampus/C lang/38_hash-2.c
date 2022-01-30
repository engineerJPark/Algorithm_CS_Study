// 체이닝은 연결리스트를 통해 특정한 키를 가지는 항목들을 연결해서 저장한다.
// 같은 key에 대한 중복을 허용

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct{
	int id;
	char name[20];
} Student;

//하나의 key에 여러 data가 들어갈 수 있게 해주는 구조체다. Student * 의 주소를 담는 구조체
typedef struct{
	Student * data;
	struct Bucket * next;
} Bucket;

//해시테이블 초기화
void init(Student ** hashTable){
	for(int i = 0; i < TABLE_SIZE; i++){
		hashTable[i] = NULL;
	}
}

//해시테이블 메모리 반환
void destructor(Student ** hashTable){
	for(int i = 0; i < TABLE_SIZE; i++){
		if(hashTable[i] != NULL){
			free(hashTable[i]);
		}
	}
}

//검색함수
int isExist(Bucket ** hashTable, int id){
	int i = id % TABLE_SIZE;
	if(hashTable[i] == NULL) return 0;
	else{
		Bucket * cur = hashTable[i];
		while(cur != NULL){
			if(cur->data->id == id) return 1;	//id까지도 중복되는 건 거른다
			cur = cur->next;
		}
	}
	return 0;
}

//input 함수
void add(Bucket ** hashTable, Student * input){
	int i = input -> id % TABLE_SIZE;	//key 값 먼저
	if(hashTable[i] == NULL){//아무것도 없는 구역인 경우
		hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
		hashTable[i]->data = input;
		hashTable[i]->next = NULL;
	}
	else{//stack을 쌓는다.
		Bucket * cur = (Bucket*)malloc(sizeof(Bucket));
		cur->data = input;
		cur->next = hashTable[i];
		hashTable[i] = cur;
	}
}

void show(Bucket ** hashTable){
	for(int i = 0; i < TABLE_SIZE; i++){
		if(hashTable[i] != NULL){
			Bucket * cur = hashTable[i];
			while(cur != NULL){
				printf("키 : [%d] 이름 : [%s]\n", i, cur->data->name);
				cur = cur->next;
			}
		}
	}
}

int main(){
	Bucket ** hashTable;
	hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
	init(hashTable);
	
	for(int i = 0; i < INPUT_SIZE; i++){
		Student * student = (Student*)malloc(sizeof(Student));
		student->id = rand()%1000000;
		sprintf(student->name, "닝겐%d", student->id);
		if(!isExist(hashTable, student->id)){//중복되는 경우
			add(hashTable, student);
		}
	}
	
	show(hashTable);
	destructor(hashTable);
	
	return 0;
}