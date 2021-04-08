/* 
 * 백준 2164번 카드2 문제 풀이
 * 
 * Queue를 이용한 풀이
 * 
 */
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int max_num = 0;
	
	queue<int> numCardQueue;
	
	scanf("%d", &max_num);
	
	if(max_num <= 2)
	{
		printf("%d\n", max_num);
		return 0;
	}
	
	if(max_num % 2 == 1)
		numCardQueue.push(max_num);
		
	for(int i = 2; i <= max_num; i+=2)
		numCardQueue.push(i);
	
	while(numCardQueue.size() > 1)
	{
		numCardQueue.pop();
		numCardQueue.push(numCardQueue.front());
		numCardQueue.pop();
	}
	
	printf("%d\n", numCardQueue.front());
	return 0;
}

// int max_num = j;
		
// if(max_num <= 2)
// {
//     printf("%d\n", max_num);
//     continue;
// }

// max_num -= 2;

// for(int i = 2; i < max_num; i = i << 1)
// {
//     max_num -= i;
// }
// printf("%d\n",  max_num * 2);