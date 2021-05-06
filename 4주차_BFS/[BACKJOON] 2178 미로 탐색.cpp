#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int column, row;
	int x, y;
	int check[502][502] = {0};
	char map[502][502] = {0};
	queue<pair<int, int>> next_location;
	
	cin >> row >> column;
	
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= column; j++)
			cin >> map[i][j];
	
	next_location.push(make_pair(1,1));
	//cout << next_location.empty() << '\n';
	while(!next_location.empty())
	{
		x = next_location.front().first;
		y = next_location.front().second;
		//cout << count << ':' << x << ',' << y << '\n';
		
		int count = ++check[x][y];
		next_location.pop();
		
		if(check[x-1][y] == 0 && map[x-1][y] == '1')
		{
			next_location.push(make_pair(x-1,y));
			check[x-1][y] = count;
		}
		if(check[x][y-1] == 0 && map[x][y-1] == '1')
		{
			next_location.push(make_pair(x,y-1));
			check[x][y-1] = count;
		}
		if(check[x+1][y] == 0 && map[x+1][y] == '1')
		{
			next_location.push(make_pair(x+1,y));
			check[x+1][y] = count;
		}
		if(check[x][y+1] == 0 && map[x][y+1] == '1')
		{
			next_location.push(make_pair(x,y+1));
			check[x][y+1] = count;
		}
	}
	
	// for(int i = 1; i <= row; i++)
	// {
	// 	for(int j = 1; j <= column; j++)
	// 	{
	// 		cout << check[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
			
	cout << check[row][column] << "\n";
	return 0;
}