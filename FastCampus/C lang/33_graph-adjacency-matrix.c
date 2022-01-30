// 모든간선이방향성을 가지지않는그래프를무방향그래프라고 합니다.
// 모든간선에가중치가 없는그래프를비가중치 그래프라고 합니다.
// 무방향비가중치그래프가 주어졌을때연결되어있는상황을인접행렬로출력할수있습니다

#include<stdio.h>

int a[1001][1001];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);//행렬의 크기
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for(int i = 1; i <= n; i++)//모든 해 보여줌
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}