// 1) 라빈 카프 문자열 매칭 알고리즘은 평균적으로 O(N + M)의 시간 복잡도를 가집니다.
// 2) 라빈 카프 알고리즘은 때에 따라서는 KMP 알고리즘보다 빠르게 동작하기도 합니다.
// 3) 하지만 라빈 카프 알고리즘은 특정한 상황에서 KMP 알고리즘보다 매우 느리게 동작할 수 있습니다.

#include <stdio.h>
#include <string.h>

char * parent = "acabacdabac";
char * pattern = "abacdab";

// 같은 문장인지 확인하는 함수
void check(char * parent, char * pattern, int start){
	int found = 1;
	int patternSize = strlen(pattern);
	for(int i = 0; i < patternSize; i++){
		if(parent[start + i] != pattern[i]){ found = 0; break; } // 완전 일치하면 break가 안된다
	}
	if(found){ printf("matched in index %d\n", start + 1); }
}

//문자열의 해쉬값 예시
// “abacdab” = 97 ∗ 2^6 + 98 ∗ 2^5 + 97 ∗ 2^4 + 99 ∗ 2^3 + 100 ∗ 2^2 + 97 ∗ 2^1 + 98 ∗ 2^0
//다음 해시 값 = 2 * (현재 해시 값 – 가장 앞에 있는 문자의 수치) + 새 문자의 수치

// 라빈카프 알고리즘
void rabinKarp(char * parent, char * pattern){
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	int parentHash = 0, patternHash = 0, power = 1;
	
	for(int i = 0; i <= patternSize; i++){
		if(i == 0){
			for(int j = 0; j < patternSize; j++){ // 초기 해쉬값 구하기
				//patternSize - 1이 마지막 문자의 위치다.
				parentHash = parentHash + parent[patternSize - 1 - j] * power;
				patternHash = patternHash + pattern[patternSize - 1 - j] * power;
				if(j < patternSize - 1) power = power * 2;
			}
		}
		// 초기값 이후는 recursion eqn으로 update
		// i - 1 가장 맨앞 index
		// i는 새로 update된 것
		else{ parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i]; }
		if(parentHash == patternHash) check(parent, pattern, i);
	}
}

int main(){
	rabinKarp(parent, pattern);
	
	return 0;
}