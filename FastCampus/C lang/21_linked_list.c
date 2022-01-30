//연결리스트

#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data){
	arr[count] = data;
	count ++;
}

void addFirst(int data){
	for(int i =count; i >= 0; i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

void show(){
	for(int i = 0; i < count; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

void delete(int idx){
	int i = 0;
	for(i = idx;i<count;i++){
		arr[i]=arr[i+1];
	}
	count--;
}

int main(void){
	addBack(1);
	addBack(2);
	addBack(3);
	addBack(4);
	addBack(5);
	
	addFirst(1);
	addFirst(2);
	addFirst(3);
	
	show();
	
	delete(4);
	show();
	
	return 0;
}