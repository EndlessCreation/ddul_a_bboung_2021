
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int dist[102][102];
string maze[102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> maze[i];
		maze[i] = '0' + maze[i];
	}
	dist[1][1] = 1;
	queue<pair<int, int>> Q;
	Q.push({ 1,1 });
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) { //상하좌우 칸을 살펴봄
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue; // 범위 밖일 경우 넘어감
			if (dist[nx][ny]>0 || maze[nx][ny] != '1') continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
			dist[nx][ny] = dist[cur.X][cur.Y]+1; // (nx, ny)를 방문했다고 명시
			Q.push({ nx,ny });
		}
	}
	cout << dist[n][m];
}