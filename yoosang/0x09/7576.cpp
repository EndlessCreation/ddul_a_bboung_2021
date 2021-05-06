
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
int dist[1002][1002];
int board[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				Q.push({ i,j });
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) { //상하좌우 칸을 살펴봄
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
			if (dist[nx][ny]>=0) continue; // 
			dist[nx][ny] = dist[cur.X][cur.Y]+1; // (nx, ny)를 방문했다고 명시
			Q.push({ nx,ny });
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {	//익지 않은 토마토가 있으면
				cout << -1;
				return 0;
			}
			mx = max(mx, dist[i][j]);
		}
	}
	cout << mx;
}