#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dist[302][302];
int dx[8] = { 1,1,-1,-1,2,-2,2,-2 };
int dy[8] = { 2,-2,2,-2,1,1,-1,-1 };

int BFS(int I, pair<int, int> start, pair<int, int> des) {
	if (start == des)
		return 0;
	memset(dist, -1, sizeof(dist));
	dist[start.X][start.Y] = 0;
	queue<pair<int, int>> Q;
	Q.push(start);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) { //나이트 모든 경로 확인
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
			if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;	// 범위 밖일 경우 넘어감
			if (dist[nx][ny] >= 0) continue;						// 방문한 경우 넘어감
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;	// (nx, ny)를 방문했다고 명시
			if (nx == des.X && ny == des.Y) {		// 목적지에 도착하면 횟수를 리턴
				return dist[nx][ny];
			}
			Q.push({ nx,ny });
		}
	}
}
int main() {
	pair<int, int> start;
	pair<int, int> des;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int I;
		cin >> I;
		cin >> start.X >> start.Y;
		cin >> des.X >> des.Y;
		cout << BFS(I, start, des) << "\n";
	}
}