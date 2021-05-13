#include <iostream>
#include <stack>

using namespace std;

int n;

int map[101][101];
int vis[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

stack<pair<int,int>> S;

void DFS(int height)
{
    while(!S.empty())
    {
        pair<int, int> cur = S.top();
        S.pop();

        for(int i = 0; i<4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx >=n || ny<0 || ny>=n)
                continue;
            if(vis[nx][ny] || map[nx][ny]<=height)  //침수되지 않은 곳만 방문 가능
                continue;

            vis[nx][ny] =1;
            S.push({nx,ny});
        }
    }
}



int main(void)
{
    int count = 0;    //안전한 영역의 갯수
    int max_count =1; //안전한 영역의 최대 갯수
    int max_height =1;

    cin >> n;

    for(int i = 0; i<n; i++)
        for(int j=0; j<n; j++)
            {
                cin >> map[i][j];
                if(max_height<map[i][j] && map[i][j] <=100)
                    max_height = map[i][j];
            }



    for(int height=1; height<=max_height; height++) //삼중 for문의 반복 횟수 최소화
    {
        count = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j] != 1 && map[i][j]>height)
                {
                    vis[i][j] =1;
                    S.push({i,j});
                    DFS(height);

                    count++;    //DFS함수를 호출할 때마다 count++
                }
            }
        }
        
        if(count > max_count)
            max_count = count;
        
        fill(&vis[0][0], &vis[100][101], 0);
        
    }

    cout << max_count;
}
