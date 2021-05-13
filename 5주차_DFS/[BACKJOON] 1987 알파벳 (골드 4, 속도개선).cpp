#include <bits/stdc++.h>

using namespace std;

int rows, cols;
int max_move = 0;
bool visited[26] = {false};
char alphabet_map[22][22] = {0};

void countMoving(int row, int col, int count)
{
    visited[alphabet_map[row][col]] = true;

    if(max_move < count)
        max_move = count;
        
    if(row < rows - 1 && visited[alphabet_map[row+1][col]] != true)
        countMoving(row + 1, col, count + 1);
    if(row > 0 && visited[alphabet_map[row-1][col]] != true)
        countMoving(row - 1, col, count + 1);
    if(col < cols - 1 && visited[alphabet_map[row][col+1]] != true)
        countMoving(row, col + 1, count + 1);
    if(col > 0 && visited[alphabet_map[row][col-1]] != true)
        countMoving(row, col - 1, count + 1);

    visited[alphabet_map[row][col]] = false; 
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
            cin >> alphabet_map[i];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            alphabet_map[i][j] -= 'A';
    countMoving(0, 0, 1);
    cout << max_move;

    return 0;
}