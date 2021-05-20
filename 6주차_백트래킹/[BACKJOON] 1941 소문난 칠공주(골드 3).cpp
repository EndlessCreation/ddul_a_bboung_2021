#include <bits/stdc++.h>

#define SIZE 5
#define SIZE2D 25
#define MOVELIMIT 7

using namespace std;

int num_of_case = 0, adjacent_count = 0;
bool visited[25] = {false};
char seats[25];
vector<int> permutation(25, 0);

/*
* S가 4개 이상 있는지 확인하는 함수
*/
bool isMoreThanFourSoms()
{
    int num_of_s = 0;
    for(int i = 0; i < SIZE * SIZE; i++)
         if(permutation[i] == 1 && seats[i] == 'S')
            num_of_s++;
    return (num_of_s >= 4) ? true : false;
}

/*
* 인접한 것을 확인하기 위해 처음 S의 위치부터 BFS로 탐색하는 함수
* 주위의 1인 지점만 탐색하며 각 탐색마다 count를 1씩 증가시킴
*/
void countAdjacent(int index, int count)
{
    if(index == -1)
        return;

    adjacent_count++;
    visited[index] = true;
        
    if(index + 5 < SIZE2D - 1 && permutation[index + 5] == 1 && visited[index + 5] == false)
        countAdjacent(index + SIZE, count + 1);
    if(index - 5 > 0 && permutation[index - 5] == 1 && visited[index - 5] == false)
        countAdjacent(index - SIZE, count + 1);
    if((index % 5) < SIZE - 1 && permutation[index + 1] == 1 && visited[index + 1] == false)
        countAdjacent(index + 1, count + 1);
    if((index % 5) > 0 && permutation[index - 1] == 1  && visited[index - 1] == false)
        countAdjacent(index - 1, count + 1);
}

/*
* S의 처음 위치를 반환하는 함수
*/
int findFirstIndex()
{
    for(int i = 0; i < SIZE2D; i++)
        if(permutation[i] == 1)
            return i;
    return -1;
}

/*
* 수열이 인접한지 확인하는 함수
* countAdjeacent()에서
*/
bool isAdjacent()
{
    adjacent_count = 0;
    memset(visited, false, sizeof(bool) * 25);
    countAdjacent(findFirstIndex(), 0);
    
    return (adjacent_count >= 7) ? true : false;
}

/*
* 25개의 위치중 7개를 선택하고 해당 위치를 기반으로 경우의 수를 게산하는 함수()
* next_permutation 함수를 이용해 25Combination7 을 구현
*/
void countNumOfCase()
{
    do{
        if(isMoreThanFourSoms() && isAdjacent())
            num_of_case++;
    }
    while (next_permutation(permutation.begin(), permutation.end()));
}
/*
* 테스트 함수
*/
void test()
{
    permutation[5] = 1;
    permutation[6] = 1;
    permutation[7] = 1;
    permutation[8] = 1;
    permutation[9] = 1;
    permutation[11] = 1;
    permutation[16] = 1;

    for(int i = 0; i < SIZE; i++)
    {
    	for(int j = 0; j < SIZE; j++)
            cout << seats[i*5 + j];
        cout << '\t';
        for(int j = 0; j < SIZE; j++)
            cout << permutation[i*5 + j];
        cout << '\n';
    }
    cout << '\n';
    cout << isMoreThanFourSoms() << ',' << isAdjacent() << '\n';

    fill(permutation.begin(), permutation.end(), 0);
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    for(int i = 0; i < SIZE; i++)
    	cin >> seats + i * 5;

    //test();

    fill(permutation.begin()+18, permutation.begin()+25, 1);

    countNumOfCase();

    cout << num_of_case << '\n';
    
    return 0;
}
