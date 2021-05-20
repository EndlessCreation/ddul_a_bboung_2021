#include <iostream>
#include <queue>
using namespace std;

int isused[5][5] = {0, };        //해당 학생이 저장됨을 나타내는 배열
char room[5][5];        //교실
int cnt_s=0;    //이다솜파 학생 수
int cnt_y=0;    //임도연파 학생 수
int cnt_grp=0;  //카운트된 그룹 수

queue<pair<int, int>> q;

void func(int r, int c) //학생을 추가하거나 arr을 출력하도록 하는 함수
{
    if(cnt_y == 4)                    //임도연파 학생이 4명이 되면 더이상 진행하지 않는다.
        return;

    if(cnt_s+cnt_y == 7 && cnt_s>=4 ) //학생을 추가할 필요가 없는 경우 cnt_grp++ 한다.
    {
        /* 디버깅용
        cout<< "grp "<<cnt_grp << endl;
        
        for(int i = 0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(isused[i][j])
                {
                    cout<< "(" <<i<<", "<<j<<")" <<endl;
                }
            }
        }
        */
        cnt_grp++;
        return;
    }

    for(int i = r; i<5; i++) 
    {
        for(int j = c; j<5; j++)
        {
            if(i!=0 && j!=0 && !isused[i-1][j] && !isused[i][j-1] && cnt_y+cnt_s !=0 ) continue; //행, 열이 0이 아닌데 왼쪽, 위쪽 모두 사용하지 않은 경우
            if(i == 0 && j!=0 && !isused[i][j-1] && cnt_y+cnt_s !=0 ) continue; //행이 0일 때 왼쪽 사용하지 않은경우
            if(i != 0 && j==0 && !isused[i-1][j] && cnt_y+cnt_s !=0 ) continue;  //열이 0일 때 위쪽을 사용하지 않은 경우 continue
            
            //cout << i<< " " << j << endl; //디버깅용
            if(!isused[i][j])
            {
                if(room[i][j] == 'Y')
                {
                    isused[i][j] = 1;
                    cnt_y++;

                    if(c!=4)
                        func(r, c+1);
                    else
                        func(r+1, 0);
                
                    isused[i][j] = 0;
                    cnt_y--;
                }
                else if(room[i][j] == 'S')
                {
                    isused[i][j] = 1;
                    cnt_s++;

                    if(c!=4)
                        func(r, c+1);
                    else
                        func(r+1, 0);

                    isused[i][j] = 0;
                    cnt_s--;
                }
            }

        }
        
    }
}

int main()
{
    for(int i = 0; i<5; i++)
    {
        cin >> room[i];
    }

    func(0, 0);

    cout << cnt_grp;

/* 디버깅용
    for(int i = 0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout << room[i][j];
        }
        cout << endl;
    }
    */ 
}