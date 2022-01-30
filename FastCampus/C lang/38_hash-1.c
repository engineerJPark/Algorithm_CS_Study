/*
많은메모리 소모, 빠른 데이터 처리
특정값을 찾을 때에는 key로 접근한다. 그 key를 index라고 한다.
key 중복을 collision이라고 한다.

hashing은 division method를 이용. 나머지를 key로 이용한다는 것.
테이블의 크기(나누기 크기)는 prime number로 설정한다.

충돌 처리
1. 선형조사법,이차조사법 : 충돌 발생항목을 테이블의 다른 위치에 저장한다.
2. 체이닝 : 해시 테이블의 하나의 버킷에 여러개의 항목을 저장한다.
*/

// 선형조사법

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

// 빈 공간 찾기
int findEmpty(Student ** hashTable, int id){
	int i = id % TABLE_SIZE;
	while(1){
		if(hashTable[i % TABLE_SIZE] == NULL){
			return i % TABLE_SIZE;
		}
		i++;
	}
}

// 특정한 ID 값에 매칭되는 데이터를 해시 테이블 내에서 찾습니다.
int search(Student ** hashTable, int id){
	int i = id % TABLE_SIZE;
	while(1){
		if(hashTable[i % TABLE_SIZE] == NULL) return -1;	//오류 출력
		else if(hashTable[i % TABLE_SIZE]->id == id) return i; //해당 해쉬 아이디값
		i++;
	}
}

//data input
void add(Student ** hashTable, Student * input, int key){
	hashTable[key] = input;
}


//data output
Student * getValue(Student ** hashTable, int key){
	return hashTable[key];
}

void show(Student ** hashTable){
	for(int i = 0; i < TABLE_SIZE; i++){
		if(hashTable[i] != NULL){
			printf("키 : [%d] 이름 : [%s]\n", i, hashTable[i]->name);
		}
	}
}

int main(){
	Student ** hashTable;
	hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	init(hashTable);
	
	for(int i = 0; i < INPUT_SIZE; i++){
		Student * student = (Student*)malloc(sizeof(Student));
		student->id = rand()%1000000;
		sprintf(student->name, "사람%d", student->id);
		if(search(hashTable, student->id) == -1){
			int index = findEmpty(hashTable, student->id);
			add(hashTable, student, index);
		}
	}
	

	
	show(hashTable);
	destructor(hashTable);
	
	return 0;
}

// 이차 조사법
// 1,4,9,16,... 이렇게 제곱수로 점프해서 중복되는 데이터를 입력한다.
// 경우에 따라선 해시테이블의 크기를 계속 확장해야하는 경우도 있다.