#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	
	int testcase = 0;
	
	cin >> testcase;
	
	while(testcase--)
	{
		deque<int> array;
		int value = 0;
		int frontPop = 0, endPop = 0, isReverse = 0;
		int arraySize = 0, pushCount = 0, pushLimit = 0;
		string command;
		string arrayString;
		
		cin >> command;
		
		for(int i = 0; i < command.size(); i++)
		{
			if(command[i] == 'R')
				isReverse = !isReverse;
			else if(command[i] == 'D')
			{
				if(isReverse)
					endPop++;
				else
					frontPop++;
			}
		}
		cin >> arraySize;
		cin >> arrayString;
		pushLimit = arraySize - frontPop - endPop;
		
		if(pushLimit < 0)
		{
			printf("error\n");
			continue;
		}
		
		for(int i = 1; i < arrayString.size(); i++)
		{
			char num = arrayString[i];
			if(num >= '0' && num <= '9')
			{
				value = value * 10 + (num - '0');
			}
			else
			{
				
				if(frontPop != 0)
				{
					value = 0;
					frontPop--;
					continue;
				}
				else
				{
					if(pushCount < pushLimit)
						pushCount++;
					else
						break;
						
					array.push_back(value);
					value = 0;
				}
			}
		}
		
		int start = isReverse ? pushLimit - 1 : 0;
		int end = isReverse ? 0 : pushLimit - 1;
		int plus = isReverse ? -1 : 1;
		
		if(array.size() == 0)
			printf("[]\n");
		else
		{
			printf("[");
			for(; start != end; start += plus)
				printf("%d,", array[start]);
			printf("%d]\n", isReverse ? array.front() : array.back());
		}
		
	}
	
	return 0;
}