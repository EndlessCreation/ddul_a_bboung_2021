#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	
	int order = 1;
	
	while(1)
	{
		char top;
		int countChange = 0;
		string bracket;
		vector<char> stack;
		
		cin >> bracket;
		
		if(bracket[0] == '-')
			break;
		
		stack.push_back(bracket[0]);
		for(int i = 1; i < bracket.size(); i++)
		{
			if(stack.back() == '{' && bracket[i] == '}')
				stack.pop_back();
			else
				stack.push_back(bracket[i]);
		}
		
		
		while(stack.back() == '{')
		{
			stack.pop_back();
			if(stack.back() == '{')
				countChange++;
			else
				countChange+=2;
			stack.pop_back();
			
		}
		countChange += stack.size()/2;
		
		printf("%d. %d\n", order++, countChange);
	}
	return 0;
}