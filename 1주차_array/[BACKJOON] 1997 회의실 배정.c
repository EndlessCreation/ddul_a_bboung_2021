#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct job{
    int start;
    int end;
};

struct job *jobs;
long *jobV;

void qsort(int start, int end)
{
	long p=jobV[(start + end)>>1];
	int s=start;
	int e=end;

	while(s<=e)
	{
		while(jobV[s] < p && s <= e) s++;
		while(jobV[e] > p && s <= e) e--;

		if(s<=e)
		{
			long tmp = jobV[s];
			jobV[s] = jobV[e];
			jobV[e] = tmp;
			s++; e--;
		}
	}

	if(start<e) qsort(start,e);
	if(s<end) qsort(s, end);
}

int main(void)
{
    int T, end, count=1;
    scanf("%d", &T);
    jobs = (struct job *)malloc(sizeof(struct job) * T);
    jobV = (long *)jobs;

    for( int i=0; i<T; i++ )
        scanf("%d %d", &jobs[i].start, &jobs[i].end);

	qsort(0, T-1);
        
	end=jobs[0].end;
    for( int i=1; i<T; i++ ) 
    {
        if(end < jobs[i].start) 
        {
            end = jobs[i].end;
            count++;
        }
    }

    printf("%d", count);
}