// O(N + M)
// matching 전에 접두사와 접미사가 일치하는 최대길이를 기록하는 table을 만든다.
// 알고리즘 검색해보기

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * parent = "acabacdabac";
char * pattern = "abacdab";

int * makeTable(char * pattern){
	int patternSize = strlen(pattern);
	int * table = (int *)malloc(sizeof(int) * patternSize);
	for(int i = 0; i < patternSize; i++){
		table[i] = 0;
	}
	//start
	int j = 0;
	for(int i = 1; i < patternSize; i++){
		while(j > 0 && (pattern[i] != pattern[j])){
			j = table[j - 1]; // 일치 안하면 마지막으로 일치했던 순간(table[j-1])으로 돌아가서 다시 체크
		}
		if (pattern[i] == pattern[j]){
			table[i] = ++j;
		}
	}
	
	return table;
}

// 문자열 매칭
// 불일치하면 j를 마지막으로 일치했던 순간(table[j-1])으로 돌아가서 다시 체크
// 매칭에 성공한다면, table[j]의 위치로 이동해서 다시 검사 - 단 한번만 매칭됐는지 확인한다

void KMP(char * parent, char * pattern){
	int * table = makeTable(pattern);
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	int j = 0;
	for(int i = 0; i < parentSize; i++){
		while(j > 0 && parent[i] != pattern[j]){ //패턴 불일치시
			j = table[j - 1];
		}
		if(parent[i] == pattern[j]){
			if(j == patternSize - 1){
				printf("[인덱스 %d]에서 매칭 성공\n", i - patternSize + 2);
				j = table[j];
			}
			else{ j++; }
		}
	}
}

int main(){
	KMP(parent, pattern);
	
	return 0;
}