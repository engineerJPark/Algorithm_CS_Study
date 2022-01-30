//단순 비교 문자열 매칭 먼저 구현해보자

#include <stdio.h>
#include <string.h>

char *parent = "ABCDEFG";
char *pattern = "EF";

int main(){
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	
	for(int i = 0; i <= parentSize - patternSize; i++){
		int found = 1;
		for(int j = 0; j < patternSize; j++)
		{
			if(parent[i + j] != pattern[j]){ found = 0; break; }
		}
		if(found){
			printf("found at index %d\n", i + 1);
		}
	}
	
	return 0;
}