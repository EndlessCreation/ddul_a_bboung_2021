# BFS : (Breadth First Search)  
  
다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘  
  
BFS는 좌표를 담을 큐가 필요하다.  
  
```c++
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.

  while(!Q.empty()){

    pair<int,int> cur = Q.front();
    Q.pop();                          //큐에서 원소를 하나 꺼낸다.

    for(int dir = 0; dir < 4; dir++)  //꺼낸 원소의 상하좌우 칸을 살펴본다.
    { 
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];       // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 Pass
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 이동 가능한 칸이 아닐 경우 Pass

      vis[nx][ny] = 1;  // (nx, ny)를 방문했다고 명시
      Q.push({nx,ny});  // 큐에 삽입
    }
  }
```  

---
  
  
### [활용]  

어떤 좌표와 이어진 모든 칸을 확인하려는 경우
(Flood Fill)

거리 측정이나 최단경로를 찾아야 하는 경우

---

### [해결 과정]  

좌표를 담을 큐를 하나 만들어서  
시작할 좌표를 큐에 담고  

큐를 팝할때 큐의 상하좌우를 살펴보고  
해당하는 좌표를 큐에 넣는 작업 진행한다.  

큐가 빌때까지 이 작업을 반복한다.  
  
모든칸이 큐에 1번씩 들어가므로 시간복잡도는 칸이 N개일때 O(N)  
  
---
  
### [문제 해결 팁]

* 이어진 칸의 넓이를 확인하고 싶은 경우  
팝 횟수를 카운트 한다.

* 이어진 영역이 하나가 아닌 경우  
이중 for문으로 시작점이 될 수 있는 곳을 찾으면 된다고 한다.  
시간복잡도는 O(nm)이 든다.  

* 시작점이 여러개인 경우  
큐에 여러개의 시작점을 모두 넣고 시작하면  
한번의 BFS로 자연스럽게 거리계산이 된다.  

* 큐에 추가되는 칸들은 아래와 같은 순서로 추가된다.  
거리가 0인 칸들, 거리가 1인 칸들, 거리가 2인 칸들 . . .  
큐에 먼저 추가된 칸 근처를 먼저 탐색한다.

* 특정 조건을 달성했을때 프로그램이 끝나도록 설정하면  
while문이 끝났을때 조건을 달성하지 못했다는 것을 알 수 있다.
```c++
            //앞부분 생략
            if(nx <0 || nx>=r || ny <0 || ny >=c)
            {
                cout << jihoon[cur.first][cur.second];
                return 0; //조건을 달성한 경우 결과값 출력 후 프로그램 종료
            }
            if(jihoon[nx][ny] != 0 || maze[nx][ny] == '#')
                continue;
            if(jihoon[cur.first][cur.second]+1 >= fire[nx][ny] && fire[nx][ny] != 0)
                continue;          
          
            jihoon[nx][ny] = jihoon[cur.first][cur.second]+1;
            Q.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;  //조건을 달성하지 못한 경우 불가능 메세지 출력 후 프로그램 종료
```

