#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	
	int input_line, good_friend;
	long long max_pair = 0;
	string name;
	vector<queue<int>> name_length(21);
	queue<int> order;
	
	cin >> input_line >> good_friend;
	
	for(int i = 0; i < good_friend; i++)
	{
		cin >> name;
		name_length[name.size()].push(i);
		order.push(name.size());
	}
	
	for(int i = 0; i < input_line - 1; i++)
	{
		int now_length = order.front();
		name_length[now_length].pop();
		order.pop();
		
		if(i + good_friend < input_line)
		{
			cin >> name;
			name_length[name.size()].push(i);
			order.push(name.size());
		}
		
		max_pair += name_length[now_length].size();
	}
	
	printf("%lld\n", max_pair);
	return 0;
}