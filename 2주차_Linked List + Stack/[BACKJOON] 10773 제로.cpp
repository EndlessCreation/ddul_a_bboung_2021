#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, t;
	int result = 0;
	
	vector<int> stack;
	
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		
		if(t == 0)
		{
			result -= stack.back();
			stack.pop_back();
		}
		else
		{
			stack.push_back(t);
			result += t;
		}
	}
	
	// for(auto i : stack)
	// 	result += i;
	printf("%d", result);

	return 0;
}