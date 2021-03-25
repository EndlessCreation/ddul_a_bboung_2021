#include <stdio.h>

char map[29][29] = {0}, check[29][29] = {0};
int house[400] = {0};

void find_complex(int r, int c, int h)
{
	if(check[r][c] == 1)
		return;
	
	check[r][c] = 1;
	(house[h])++;
	
	if(map[r][c+1] == '1' && check[r][c+1] == 0)
		find_complex(r, c+1, h);
	if(map[r][c-1] == '1' && check[r][c-1] == 0)
		find_complex(r, c-1, h);
	if(map[r+1][c] == '1' && check[r+1][c] == 0)
		find_complex(r+1, c, h);
	if(map[r-1][c] == '1' && check[r-1][c] == 0)
		find_complex(r-1, c, h);
}

void qsort(int start, int end)
{
	int p=house[(start + end)>>1];
	int s=start;
	int e=end;

	while(s<=e)
	{
		while(house[s] < p && s <= e) s++;
		while(house[e] > p && s <= e) e--;

		if(s<=e)
		{
			int tmp = house[s];
			house[s] = house[e];
			house[e] = tmp;
			s++; e--;
		}
	}
	if(start<e) qsort(start,e);
	if(s<end) qsort(s, end);
}

int main(void) {
	int N;
	int h = 0;
	
	scanf("%d", &N);
	N++;
	
	for(int i = 1; i < N; i++)
		scanf("%s", &(map[i][1]));	
	
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(map[i][j] == '0' || check[i][j] == 1)
				continue;
			else
			{
				find_complex(i, j, h);
				h++;
			}
		}
	}
	
	qsort(0,h-1);
	
	printf("%d\n", h);
	for(int i = 0; i < h; i++)
		printf("%d\n", house[i]);
}
