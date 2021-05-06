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
			board[y][x] = 1;          //�Է� ������ �� ���� �ʰ� Ǯ� ���� �߻� -> board[x][y]=1;
		}							 //������ ��ǥ �Է�

		int num = 0;				

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 1 || vis[i][j]) continue;	//���� ���߰� ���ų� �湮�� ���� �ִٸ� �н�
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
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;	//���� ���
						if (vis[nx][ny] || board[nx][ny] != 1)continue;			//���� ���߰� ���ų� �湮�� ���� �ִٸ� �н�
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << num <<'\n';
		memset(board, 0, sizeof(board));		//*�׽�Ʈ���̽����� �ʱ�ȭ �ʿ�*
		memset(vis, 0, sizeof(vis));
	}
}
