/*#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second

string board[1002];
int jih[1002][1002];
int fire[1002][1002];
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			fire[i][j] = -1;
			jih[i][j] = -1;
		}
	}
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] != 'F') continue;
			Q1.push({ i,j });
			fire[i][j] = 0;
		}
	}
	while (!Q1.empty()) {
		pair<int, int> cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] != 'J') continue;
			jih[i][j] = 0;
			Q2.push({ i,j });
		}
	}
	while (!Q2.empty()) {
		pair<int, int>cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << jih[cur.X][cur.Y] + 1;
				return 0;
			}
			if (fire[nx][ny] != -1 && fire[nx][ny] <= jih[cur.X][cur.Y] + 1)continue;
			if (board[nx][ny] == '#' || jih[nx][ny] >= 0)continue;
			jih[nx][ny] = jih[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";

}*/