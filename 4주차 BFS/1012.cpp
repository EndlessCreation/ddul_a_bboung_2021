#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define X first
#define Y second

int board[52][52];
bool vis[52][52];
int t;
int m, n, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;          //입력 조건을 잘 읽지 않고 풀어서 오류 발생 -> board[x][y]=1;
		}							 //배추의 좌표 입력

		int num = 0;				

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 1 || vis[i][j]) continue;	//땅에 배추가 없거나 방문한 적이 있다면 패스
				queue<pair<int, int>> Q;
				num++;			
				vis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;	//범위 벗어남
						if (vis[nx][ny] || board[nx][ny] != 1)continue;			//땅에 배추가 없거나 방문한 적이 있다면 패스
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << num <<'\n';
		memset(board, 0, sizeof(board));		//*테스트케이스마다 초기화 필요*
		memset(vis, 0, sizeof(vis));
	}
}
