#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

char board[102][102];	// ��ȭ�� 
int vis[102][102];	// �� üũ 
int N;
int R, G, B, RG;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){	// ��ȭ�� �Է� 
  	for(int j = 0;j < N; j++){
  		cin >> board[i][j];
	}
  }
  queue<pair<int,int> > Q;
  
  for(int i = 0; i < N; i++){	// R�� ��� 
    for(int j = 0; j < N; j++){
      if(board[i][j] != 'R' || vis[i][j] == 1) continue;
      R++;
      vis[i][j] = 1;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(vis[nx][ny] == 1 || board[nx][ny] != 'R') continue;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
	}
  }
  
  for(int i = 0; i < N; i++){	// G�� ��� 
    for(int j = 0; j < N; j++){
      if(board[i][j] != 'G' || vis[i][j] == 2) continue;
      G++;
      vis[i][j] = 2;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(vis[nx][ny] == 2 || board[nx][ny] != 'G') continue;
          vis[nx][ny] = 2;
          Q.push({nx,ny});
        }
      }
	}
  }
  
  for(int i = 0; i < N; i++){	// B�� ��� 
    for(int j = 0; j < N; j++){
      if(board[i][j] != 'B' || vis[i][j] == 3) continue;
      B++;
      vis[i][j] = 3;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(vis[nx][ny] == 3 || board[nx][ny] != 'B') continue;
          vis[nx][ny] = 3;
          Q.push({nx,ny});
        }
      }
	}
  }
  
  int vis[102][102];
  for(int i = 0; i < N; i++){	// ������ ��� 
    for(int j = 0; j < N; j++){
      if(board[i][j] == 'B' || vis[i][j] == 1) continue;
      RG++;
      vis[i][j] = 1;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
          if(vis[nx][ny] == 1 || board[nx][ny] == 'B') continue;
          vis[nx][ny] = 1;
          Q.push({nx,ny});
        }
      }
	}
  }
  cout << R + G + B << ' ' << RG + B;
}
