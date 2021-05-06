# **BFS(Breadth First Search)**
    다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘
   
   <img src="https://media.vlpt.us/images/sukong/post/103fbeed-3f70-4074-9a7d-76915a7764f2/BFS.png" width="200">


## **BFS와 DFS의 차이**
<img src="https://ww.namu.la/s/1fe9246903b78fae07577b243a0b22791e02cb39640d5cbaae10d9849343b4ea6f162a9a677a5892fbf7819abd4ef7221ebd3608849cfb66793411fb5e643951a2fcd15b678e35092e41fcede5babc819a4091cceb5e587366ce80debc4bea65" width="400" height="200">

## **BFS의 특징**
    * 두 노드사이의 최단경로를 탐색할때 활용하기 좋은 방식이다. 멀리 떨어진 노드는 나중에 탐색하는 방식이기 때문이다.
    * 큐를 활용해서 탐색할 노드의 순서를 저장하고 큐에 저장된 순서대로 탐색한다. 선입선출의 방식을 활용해야 하기 때문에 큐를 활용한다.

## **코드 예시**
"파란 칸에 해당하는 좌표를 찾아가며 출력하는 프로그램"
``` c++
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] ={
 {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} 
 }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); 
    Q.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      Q.push({nx,ny});
    }
  }
}
```
"BOJ 1926번"
``` c++
#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n;
int m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}       //여기까지 입력

	int mx = 0; //그림크기의 최댓값
	int num = 0; //그림의 수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j]==0 ) continue; //그림의 시작점이 될 수 있는 곳 찾기
			num++; //새로운 그림을 찾았기 때문의 그림의 수 증가
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0; //그림의 크기
			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area); //그림크기의 최댓값을 새로 대입
		}
	}
	cout << num << '\n' << mx;
	
}
```