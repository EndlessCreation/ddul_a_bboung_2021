#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct location {
	int x;
	int y;
	int isCrashed;
} Location;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int column, row;
	int x, y;
	
	char map[1002][1002] = {0};
	int count_map[1002][1002][2] = {0};
	int bfsX[4] = {-1, 0, 1, 0};
	int bfsY[4] = {0, -1, 0, 1};
	
	queue<Location> next_location;
	
	cin >> row >> column;
	
	for(int i = 1; i <= row; i++)
		for(int j = 1; j <= column; j++)
			cin >> map[i][j];
	
	Location first = {1, 1, 0};
	next_location.push(first);
	
	while(!next_location.empty())
	{
		Location cur = next_location.front();
		Location next;
		int curX = cur.x;
		int curY = cur.y;
		int crash = cur.isCrashed;
		int count = ++count_map[curX][curY][crash];
		next_location.pop();
		
		for(int i = 0; i < 4; i++)
		{
			next = {curX + bfsX[i], curY + bfsY[i], crash};
			
			if(count_map[next.x][next.y][crash] == 0 && map[next.x][next.y] == '0')
			{
				next_location.push(next);
				count_map[next.x][next.y][next.isCrashed] = count;
			}
			if(crash == 0 && map[next.x][next.y] == '1')
			{
				next.isCrashed = 1;
				next_location.push(next);
				count_map[next.x][next.y][next.isCrashed] = count;
			}
		}
	}
	
	// for(int i = 1; i <= row; i++)
	// {
	// 	for(int j = 1; j <= column; j++)
	// 		cout << count_map[i][j][0] << ' ';
	// 	cout << '\n';
	// }
	// cout << '\n';
	// for(int i = 1; i <= row; i++)
	// {
	// 	for(int j = 1; j <= column; j++)
	// 		cout << count_map[i][j][1] << ' ';
	// 	cout << '\n';
	// }	
	// cout << '\n';
	
	if(count_map[row][column][0] == 0 && count_map[row][column][1] == 0)
		cout << -1 << '\n';
	else if(count_map[row][column][0] == 0 && count_map[row][column][1] != 0)
		cout << count_map[row][column][1] << '\n';
	else if(count_map[row][column][0] != 0 && count_map[row][column][1] == 0)
		cout << count_map[row][column][0] << '\n';
	else
		cout << min(count_map[row][column][0], count_map[row][column][1]) << '\n';
	return 0;
}