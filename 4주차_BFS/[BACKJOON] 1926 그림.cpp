#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int column, row, picture_num = 0, max = 0;
	int x, y;
	char map[502][502] = {0}, check[502][502] = {0};
	queue<pair<int, int>> next_location;
	
	cin >> row >> column;
	
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= column; j++)
			cin >> map[i][j];
			
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= column; j++)
		{
			//cout << i << ',' << j << '=' << map[i][j]<<" ??\n";
			if(map[i][j] == '1' && check[i][j] == 0)
			{
				int count = 0;
				next_location.push(make_pair(i,j));
				//cout << next_location.empty() << '\n';
				while(!next_location.empty())
				{
					x = next_location.front().first;
					y = next_location.front().second;
					//cout << count << ':' << x << ',' << y << '\n';
					
					check[x][y] = 1;
					next_location.pop();
					count++;
					
					if(check[x-1][y] == 0 && map[x-1][y] == '1')
					{
						next_location.push(make_pair(x-1,y));
						check[x-1][y] = 1;
					}
					if(check[x][y-1] == 0 && map[x][y-1] == '1')
					{
						next_location.push(make_pair(x,y-1));
						check[x][y-1] = 1;
					}
					if(check[x+1][y] == 0 && map[x+1][y] == '1')
					{
						next_location.push(make_pair(x+1,y));
						check[x+1][y] = 1;
					}
					if(check[x][y+1] == 0 && map[x][y+1] == '1')
					{
						next_location.push(make_pair(x,y+1));
						check[x][y+1] = 1;
					}
				}
				//cout << count << '\n';
				picture_num++;
				if(max < count)
					max = count;
			}
		}
	}
	
	cout << picture_num << "\n" << max << "\n";
	return 0;
}