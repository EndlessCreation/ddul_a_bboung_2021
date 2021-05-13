#include <iostream>
#include <queue>

using namespace std;

int board[502][502];
bool vis[502][502]; //해당칸을 방문했는지 기록

int dx[4] = {1, -1, 0, 0};  //상하좌우를 나타내는 배열
int dy[4] = {0, 0, -1, 1};

queue<pair<int,int>> Q;

int n, m; //도화지 크기



int find()
{
    int s=1; //find()를 호출하기 전 이미 한칸을 방문했으므로 넓이는 1부터 시작

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for(int i = 0; i<4; i++) //상하좌우 각각 1번씩 총 4번 반복
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx >n || ny<0 || ny>m)
                continue;
            
            if(vis[nx][ny] || board[nx][ny] != 1)
                continue;

            vis[nx][ny] =1;

            Q.push({nx,ny});
            s++; //이어서 방문하면 넓이를 나타내는 변수 증가
        }
        
    }
    return s;
}

int main(void)
{
    int count = 0; //그림 갯수
    int max = 0; //가장 넓은 그림의 넓이

    //도화지의 세로크기 n과 가로크기 m 입력
    
    cin >> n >> m;
    //그림의 정보
    //n줄을 입력받는다.
    for(int i = 0; i<n; i++)
    {
        //m칸을 입력받는다.
        for(int j=0; j<m; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
        }
    }

    //이제 이거로 해결한다.
   for(int i = 0; i<n; i++)
   {
       for (int j = 0; j <m; j++)
       {
           if(board[i][j] == 1 && vis[i][j] !=1) // 그림이면서 아직 확인하지 않은경우
           {
               vis[i][j] = 1; //방문했음을 명시
               Q.push({i,j});

               count++; //그림의 갯수 증가

               int num = find();

               if(max < num)
               max = num;
           }
       }
   }

   cout<<count<<"\n";
   cout<<max;
}