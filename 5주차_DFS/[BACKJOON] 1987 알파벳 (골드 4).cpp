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
    if(alphabet_map[row][col] == 0 || alphabet_map[row][col] == '\n' || visited[alphabet_map[row][col] - 'A'] == true) return;
    visited[alphabet_map[row][col] - 'A'] = true;

    if(max_move < count)
        max_move = count;
        
    for(int i = 0; i < 4; i++)
        countMoving(row + directR[i], col + directC[i], count + 1);
    visited[alphabet_map[row][col] - 'A'] = false; 
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> row >> col;
    for(int i = 1; i <= row; i++)
        cin >> &alphabet_map[i][1];
    
    countMoving(1, 1, 1);
    cout << max_move;
}