#include <iostream>
#include <queue>

using namespace std;

int n, m; //미로의 크기 N*M

char maze[101][101]; //미로 char로 선언한 이유는 붙어서 입력되기 때문에 문자열로 만들어야 함

int vis[101][101] = {0, }; //0,0으로부터 거리 카운트

int dx[4] = {1, -1, 0, 0}; //상하좌우를 나타내는 배열
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> Q; //좌표를 저장하는 큐

void find()
{
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx>n || ny <0 || ny >m)
                continue;
            if(vis[nx][ny] != 0 || maze[nx][ny] != '1')
                continue;
            
            vis[nx][ny] = vis[cur.first][cur.second]+1;
            
            Q.push({nx,ny});
        }
    }
}

int main(void)
{
    //n, m 입력
    cin >> n >> m;

    //maze 입력
    for(int i = 0; i<n; i++)
    {
        cin >> maze[i]; //
    }
    
    vis[0][0] = 1; //{0,0} 에서 시작 , {0,0} 방문
    Q.push({0,0});
    find();
    
    cout<<vis[n-1][m-1];   

}