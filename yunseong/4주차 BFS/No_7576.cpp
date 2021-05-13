#include <iostream>
#include <queue>

using namespace std;

int container[1002][1002];

int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

queue<pair<int, int>> Q;

int n,m;
int tomato = 0;

int find()
{
    int max=1; //시작점이 1이므로 1부터 시작

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();

        Q.pop(); //pop할때마다 아래의 코드 실행
        for(int i = 0; i<4; i++)
        {
            int nextX=cur.first + dirX[i];
            int nextY=cur.second + dirY[i];

            if(nextX < 0 || nextX >= n || nextY<0 || nextY >= m)
                continue;
            if(container[nextX][nextY] != 0)
                continue;

            container[nextX][nextY] = container[cur.first][cur.second] + 1;

            if(max < container[nextX][nextY])
                max = container[nextX][nextY];

            Q.push({nextX,nextY});
            tomato--;
        }   
    }

    return max-1; //시작점이 1부터 시작하기 때문에 -1 반영한다.
}

int main(void)
{
    //n, m 입력
    cin >> m >> n; //가로 칸 수가 m임에 주의한다.
    
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int input;
            cin >> input;
            container[i][j] = input;

            if(input == 1)
                Q.push({i,j});
            if(input == 0)
                tomato++;
        }
    }
    
    int result = find();

    if(tomato == 0)
        cout << result;
    else
        cout << -1;


    
}