#include <bits/stdc++.h>

using namespace std;

int row, col;
int max_move = 0;
bool visited[26] = {false};
char alphabet_map[22][22] = {0};
int directR[4] = {1, 0, -1, 0};
int directC[4] = {0, 1, 0, -1};

void countMoving(int row, int col, int count)
{
    int now_alpha = alphabet_map[row][col]; 
    if(visited[now_alpha - 'A'] == true || now_alpha == 0) return;
    visited[now_alpha] = true;

    if(max_move < count)
        max_move = count;
        
    for(int i = 0; i < 4; i++)
        countMoving(row + directR[i], col + directC[i], count + 1);
    visited[now_alpha] = false;
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> row >> col;
    for(int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> alphabet_map[i][j];

    countMoving(1, 1, 1);
    cout << max_move;

    return 0;
}