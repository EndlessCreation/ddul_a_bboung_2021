#include <stdio.h>
#include <deque>
using namespace std;

int main() {
	int testcase = 0, cardNum = 0;
	char card;
	
	scanf("%d", &testcase);
	
	while(testcase--)
	{
		deque<char> string;
		
		scanf("%d", &cardNum);
		
		getchar();
		for(int i = 0; i < cardNum; i++)
		{
			scanf("%c ", &card);
			if(string.front() >= card || i == 0)
			{
				string.push_front(card);
			}
			else
			{
				string.push_back(card);
			}
		}
		
		for(int i = 0, size = string.size(); i< size; i++)
		{
			printf("%c", string[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}