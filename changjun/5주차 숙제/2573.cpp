#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[302][302];    // 배열
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int year = 0;

    while(true){    // 두 덩어리로 분리될때 까지 반복
        bool vis[302][302] = {0,};  // 방문 여부
        int area = 0;
        for(int i = 0; i < n; i++){ // DFS
            for(int j = 0; j < m; j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                area++;
                stack<pair<int,int>> S;
                vis[i][j] = 1;
                S.push({i,j});
                while(!S.empty()){
                    auto cur = S.top(); S.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        S.push({nx,ny});
                    }
                }
            }
        }
        if(area >= 2) break;
        if(area == 0){  // 다 녹았을 경우
            cout << "0";
            return 0;
        }
        int copy_board[302][302];
        for(int i = 0; i < n; i++){ // 배열 복사
            for(int j = 0; j < m; j++){
                copy_board[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < n; i++){ // 빙산 녹이기
            for(int j = 0; j < m; j++){
                int count = 0;
                if(copy_board > 0){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(copy_board[nx][ny] == 0) count++;
                    }
                    board[i][j] -= count;
                    if(board[i][j] < 0) board[i][j] = 0;
                }
            }
        }
        year++;
    }
    cout << year;
}