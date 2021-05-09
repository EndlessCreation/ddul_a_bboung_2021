// Beakjoon 1926
// 그림 판이 있을때, (1) 그림의 개수 와 (2) 그림 중 가장 큰 넓이의 크기 출력
// 그림 조건 : 가로와 세로로 연결된 경우에 같은그림 대각선인 경우는 다른 그림이다

// 1번 -> 그림의 시작점의 개수
// 2번 -> 큐에서 몇번 pop하는지 센다

#include <bits/stdc++.h>
using namespace std;
int board[502][502]; // 말 그대로 판. 1이면 갈수있고 0이면 못가는 곳
bool vis[502][502]; // 방문 여부를 기록할 곳
int n, m; // n은 행의 수, m은 열의 수
int dx[4] = {1,0,-1,0}; // 좌표 순서는 하우상좌
int dy[4] = {0,1,0,-1};
int main(void) {
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    int picMaxArea = 0;
    int picNum = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 0 || vis[i][j])
                continue; // 방문했거나 못가는 곳 제외
            picNum++; //새로운 그림 등장이므로 그림 수 증가
            int picArea = 0; // 현재 그림의 넓이 크기 측정할 변수
            queue<pair<int,int>> Q;
            vis[i][j] = 1; // 시작점 방문표시 등록
            Q.push({i,j}); // 시작점 큐에 추가
            while(!Q.empty()) {
                picArea++; // 큐에서 pop할때마다 크기가 1씩 증가한다 볼수있다
                pair<int, int> cur = Q.front(); Q.pop();
                // cout << '(' << cur.first << ", " << cur.second << ") ->"; // 현재 점 확인
                for(int dir = 0; dir < 4; dir++) { // 상하좌우 반복 x는 행 y는 열. dx,dy에 따른 순서는 하우상좌.
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위내 인지 확인
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; // 방문했거나 못가는 곳 제외
                    vis[nx][ny] = 1; //위에서 걸러지고 남은 곳은 방문해야 하는 곳이므로 방문 표시
                    Q.push({nx, ny});
                }
            }
            if(picMaxArea < picArea)
                picMaxArea = picArea;
        }
    }
    cout << picNum << '\n' << picMaxArea;
}

//
// Created by HUH on 2021-05-02.
//

