#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int column, row, input_buf, zero_check = 0;
	int x, y, max_count = 0;
	int check[502][502] = {0};
	int map[502][502] = {0};
	queue<pair<int, int>> next_location;
	
	cin >> column >> row;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= column; j++)
		{
			cin >> input_buf;
			if(input_buf == 0)
			{
				zero_check = 1;
				map[i][j] = 2;
			}
			else
			{
				if(input_buf == 1)
					next_location.push(make_pair(i,j));
				map[i][j] = input_buf;
			}
		}
	}
	
	if(zero_check == 1)
	{
		while(!next_location.empty())
		{
			x = next_location.front().first;
			y = next_location.front().second;
			//cout << count << ':' << x << ',' << y << '\n';
			
			int count = check[x][y] + 1;
			next_location.pop();
			
			if(check[x-1][y] == 0 && map[x-1][y] == 2)
			{
				next_location.push(make_pair(x-1,y));
				map[x-1][y] = 1;
				check[x-1][y] = count;
			}
			if(check[x][y-1] == 0 && map[x][y-1] == 2)
			{
				next_location.push(make_pair(x,y-1));
				map[x][y-1] = 1;
				check[x][y-1] = count;
			}
			if(check[x+1][y] == 0 && map[x+1][y] == 2)
			{
				next_location.push(make_pair(x+1,y));
				map[x+1][y] = 1;
				check[x+1][y] = count;
			}
			if(check[x][y+1] == 0 && map[x][y+1] == 2)
			{
				next_location.push(make_pair(x,y+1));
				map[x][y+1] = 1;
				check[x][y+1] = count;
			}
			
			if(max_count < count)
				max_count = count - 1;
		}
		
		
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= column; j++)
			{
				if(map[i][j] == 2)
				{
					cout << -1 << "\n";
					return 0;
				}
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
				
		cout << max_count << "\n";
	}
	else
	{
		cout << 0 << '\n';
	}
	return 0;
}