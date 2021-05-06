#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dist[22][22];
int n;
int board[22][22];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };
int eat_distance;
pair<int,int> shark;
vector<pair<int, pair<int, int>>> Eat;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int size = 2;
    int eat_count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark.X = i;
                shark.Y = j;
                board[i][j] = 0;
            }
        }
    }
    while (true) {
        Eat.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = -1;
            }
        }
        dist[shark.X][shark.Y] = 0;
        queue<pair<int, int>> Q;
        Q.push(shark);
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;   //범위를 넘어감
                if (board[nx][ny] > size)continue;  //물고기 사이즈가 큼
                if (dist[nx][ny] >= 0)continue;     //방문했으면 넘어감 방문안한곳은 -1
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                if (size > board[nx][ny] && board[nx][ny] != 0) {
                    Eat.push_back({ dist[nx][ny],{nx,ny} });
                }
                Q.push({ nx,ny });
            }
        }
        if (Eat.empty())    //먹을 물고기가 없음
            break;
        else {
            sort(Eat.begin(), Eat.end());
            eat_count++;                //먹은 횟수 추가
            ans += Eat[0].first;        //답에 지나온 거리를 더함
            shark = Eat[0].second;      //현재 상어의 위치 지정
            if (size == eat_count) {    //물고기를 충분히 먹으면 사이즈 커짐
                size++;
                eat_count = 0;
            }
            board[shark.X][shark.Y] = 0;    //물고기를 먹으면 그 자리는 비워줌
        }
    }

    cout << ans;
    return 0;
}