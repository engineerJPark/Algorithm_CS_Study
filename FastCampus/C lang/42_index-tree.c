// 컴퓨터가 2의 보수를 이용하는 것을 우리가 이용할 것이다.
// 2의 보수, 1의 보수 찾아보기
// 런타임 에러 수정
// i = index

#include <stdio.h>
#define NUMBER 7

int tree[NUMBER];

int sum(int i){
	int res = 0;
	while (i > 0){
		res += tree[i];
		i -= (i & -i);
		// i = (i & -i); // 오타친 것. 이 경우 계속 i = 1이라서 영원히 안끝난다... 오버플로우까지
	}
	return res;
}

void update(int i, int dif){ //i index에 dif만큼 더해준다.
	while(i <= NUMBER){
		tree[i] += dif;
		// 마지막 비트만큼 더하면서 뒤로 이동한다.
		i += (i & -i);
	}
}

int getSection(int start, int end){
	return sum(end) - sum(start -1);
}

int main(){
	update(1, 7);
	update(2, 1);
	update(3, 9);
	update(4, 5);
	update(5, 6);
	update(6, 4);
	update(7, 1);
	
	printf("sum of 1 to 7 : %d\n", getSection(1,7));
	printf("sum of 4 to 7 : %d\n", getSection(4,7));
	printf("+3 on index 6\n"); update(6,3);
	printf("sum of 1 to 7 : %d\n", getSection(1,7));
	printf("sum of 4 to 7 : %d\n", getSection(4,7));
	
	return 0;
}