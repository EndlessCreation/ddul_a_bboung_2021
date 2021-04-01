#include <stdio.h>

int main(void)
{
    int T, N, A[101] = {0};
    
    scanf("%d", &T);
    for(int k = 1; k <= T; k++)
    {
        int answer = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
            scanf("%d", A+i);
        
        for(int i = 0; i < N-1; i++)
        {
        	int min = 10000, min_index = 0;
        	
            for(int j = i; j < N; j++)
            {
                if(A[j] <= min)
                {
                    min = A[j];
                    min_index = j;
                }
            }
            
            int mid = (min_index+i+1)>>1;
            for(int j = i; j < mid; j++)
            {
                int tmp = A[j];
                A[j] = A[min_index-j+i];
                A[min_index-j+i] = tmp;
            }
            
            answer += min_index - i + 1;
        }
        
        printf("Case #%d: %d\n", k, answer);
    }
}