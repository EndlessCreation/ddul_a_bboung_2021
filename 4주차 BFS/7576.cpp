/*#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int n, m;
int tot[1002][1002];
int dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	queue <pair < int, int >> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tot[i][j];
			if (tot[i][j] == 1) {
				Q.push({ i,j });
			}
			if (tot[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dis = 0; dis < 4; dis++) {
			int nx = cur.X + dx[dis];
			int ny = cur.Y + dy[dis];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (dist[nx][ny] >= 0)continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1){
			cout << -1;
			return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}*/