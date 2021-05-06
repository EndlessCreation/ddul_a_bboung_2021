#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[102][102];
int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int max;
  for(int i = 0; i < N; i++){
  	for(int j = 0;j < N; j++){
  		cin >> board[i][j];
  		if(board[i][j] > max){
  			max = board[i][j];
		}
	}
  }
  queue<pair<int,int> > Q;
  int ans = 0;
  for(int h = 0; h <= max; h++){
    bool vis[102][102]={0,};
  	int area = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(board[i][j] <= h || vis[i][j] == 1) continue;
        area++;
        vis[i][j] = 1;
        Q.push({i,j});
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(board[nx][ny] <= h || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
          }
        }
  	  }
    }
    if(area > ans) ans = area;
  }
  cout << ans;
}
