#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = {};
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int max = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]||!board[i][j]) continue;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;    //i,j를 방문했다고 명시
            Q.push({ i,j });  //Queue의 시작점에 i,j를 삽입
            int size = 0;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();
                size++;
                for (int dir = 0; dir < 4; dir++) { //상하좌우 칸을 살펴봄
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                    if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
                    vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                    Q.push({ nx,ny });
                }
            }
            cnt++;
            max = max > size ? max : size;
        }
    }
    cout << cnt << "\n" << max;
}