#include <iostream>
using namespace std;

int n, m;
int can_use[10001] = {0, };      //해당 수가 몇 번 사용될 수 있는지 나타내는 배열
int arr[10];                   //출력할 수를 저장하는 배열

void func(int k) //arr[k]의 값을 저장하거나 arr을 출력하도록 하는 함수
{
    if(k==m) //k가 m보다 커서 추가로 저장할 필요가 없는 경우 출력한다.
    {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i<10001; i++) //arr[k-1]보다 큰 수만 저장한다.
    {
        if(can_use[i]>0)
        {
            arr[k] = i;
            can_use[i]--;
            func(k+1);
            can_use[i]++;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        can_use[input]++;
    }
    func(0);
}