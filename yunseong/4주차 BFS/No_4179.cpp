#include <iostream>
#include <queue>

using namespace std;

int r, c; //미로의 크기 R*C

char maze[1001][1001]; //미로

int jihoon[1001][1001] = {0, };
int fire[1001][1001] = {0, };

int dx[4] = {1, -1, 0, 0}; //상하좌우를 나타내는 배열
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> Q; //좌표를 저장하는 큐

void FireMove()
{
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx>=r || ny <0 || ny >=c)   //미로 밖으로 벗어날 수 없음
                continue;
            if(fire[nx][ny] != 0 || maze[nx][ny] == '#') //벽이나 이미 방문한 곳으로 갈 수 없음
                continue;
            
            fire[nx][ny] = fire[cur.first][cur.second]+1;

            Q.push({nx,ny});
        }
    }
}

int JihoonMove()
{
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();

        Q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx>=r || ny <0 || ny >=c)
            {
                cout << jihoon[cur.first][cur.second];
                return 0;
            }
            if(jihoon[nx][ny] != 0 || maze[nx][ny] == '#') //벽이나 이미 방문한 곳으로 갈 수 없음
                continue;
            if(jihoon[cur.first][cur.second]+1 >= fire[nx][ny] && fire[nx][ny] != 0)
                continue;            //불이 모든 길을 지나지 않을 수 있는 점에 주의해야한다. (fire ==0 인 지점이 존재)
                
            
            jihoon[nx][ny] = jihoon[cur.first][cur.second]+1;
            Q.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

int main(void)
{
    pair<int, int> J;

    //r, c 입력
    cin >> r >> c;

    //maze 입력
    for(int i = 0; i<r; i++)
    {
        cin >> maze[i];
        for(int j=0; j<c; j++)
        {
            if(maze[i][j] == 'J')
            {
                J = {i,j};      //지훈이 초기 위치 저장
                jihoon[i][j]=1;

            }    
            
            if(maze[i][j] == 'F')
            {
                Q.push({i,j});
                fire[i][j] = 1;
            }
        }
    }
    
    FireMove(); //시간에 따른 불길 표시
    Q.push(J);
    JihoonMove();
}