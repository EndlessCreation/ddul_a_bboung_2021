#include <iostream>
using namespace std;

int n;
int cnt = 0;

int check_c[40] = {0, }; //해당 열이 이미 점유되었는지 나타내는 배열 c값으로 확인
int check_rc[40] = {0, }; //해당 대각선이 이미 점유되었는지 나타내는 배열 r+c값으로 확인
int check_rcn1[40] = {0, }; //해당 대각선이 이미 점유되었는지 나타내는 배열 r-c+n-1로 확인

void func(int r) //r번째 행에 퀸을 놓을 수 있는지 확인하는 함수
{
    if(r == n) //이미 놓을 수 있는 퀸은 모두 놓았으므로 함수를 종료한다.
    {
        cnt++;
        return;
    }

    for(int c=0; c<n; c++) //c번째 열에 퀸을 놓을 수 있는지 확인한다.
    {
        if(!check_c[c] && !check_rc[r+c] && !check_rcn1[r-c+n-1])
        {

            check_c[c] = 1;
            check_rc[r+c] = 1;
            check_rcn1[r-c+n-1] = 1;

            func(r+1);          

            check_c[c] = 0;
            check_rc[r+c] = 0;
            check_rcn1[r-c+n-1] = 0;    //위의 함수가 종료되면 원래 상태로 되롤려 놓는다.
        }
    }
}
int main(void)
{
    cin >> n;
    func(0);
    
    cout << cnt;
}