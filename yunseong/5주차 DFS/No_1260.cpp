#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int vis[1001] = {0, };
int link[1001][1001] = {0, };

int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;

        link[r][c] = 1;
        link[c][r] = 1;
    }

    stack<int> s;
    s.push(v);

    while(!s.empty())
    {
        int cur = s.top();
        s.pop();

        if(vis[cur] != 1)
            cout << cur << " ";
        vis[cur] = 1;
        

        for(int next = n; next>=1; next--) // 정점 번호가 낮은것을 먼저 방문
        {
            if(vis[next] == 1 || link[cur][next] != 1)
                continue;

            s.push(next);
            //vis[next] = 1; //34행으로 변경
        }
    }

    fill_n(vis, n+1, 0);
    cout << "\n";
    
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << " " << cur;

        for(int next = 1; next <=n; next++) //정점 번호가 낮은것을 먼저 방문
        {
            if(vis[next] == 1 || link[cur][next] != 1)
                continue;

            q.push(next);
            vis[next] = 1;
        }
    }

    
}