/*#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int mx = 0;
int num = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j])continue;
			num++;
			queue<pair<int, int>> Q;
			Q.push({ i,j });
			vis[i][j] = 1;
			int area = 0;
			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dis = 0; dis < 4; dis++) {
					int nx = cur.X + dx[dis];
					int ny = cur.Y + dy[dis];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					if (board[nx][ny] != 1 || vis[nx][ny])continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\n' << mx;
}*/