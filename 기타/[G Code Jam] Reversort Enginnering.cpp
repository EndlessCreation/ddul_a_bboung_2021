#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int T, N, C;
	
	scanf("%d", &T);
	for(int k = 1; k <= T; k++)
	{
		scanf("%d %d", &N, &C);
		if(C < N-1 || C > (N*N + N)/2 - 1)
		{
			printf("Case #%d: IMPOSSIBLE\n", k);
			continue;
		}
		
		int Num[101] = {0}, index = 1;	
		vector<int> A(101,1);
		A[N] = 0;
		C -= N-1;
		
		for(int i = N; i > 0; i--)
			Num[i] = i;
				
		while(C)
		{
			int cost = min(C, N-index);
			A[index] += cost;
			C -= cost;
			index++;
			if(index > 7)
				break;
		}
		
		for(int i = N-1; i > 0; i--)
		{
			int mid = A[i]>>1;
			for(int j = 0; j < mid; j++)
			{
				int tmp = Num[i+j];
				int back = i + A[i] - j - 1;
				Num[i+j] = Num[back];
				Num[back] = tmp;
			}
			
			// for(int i = 1; i <= N; i++)
			// 	printf("%d ", Num[i]);
			// printf("\n");
		}
		
		printf("Case #%d: ", k);
		for(int i = 1; i <= N; i++)
			printf("%d ", Num[i]);
		printf("\n");
	}
	return 0;
}
