#include <iostream>
using namespace std;

int n, m;
int isused[10]; //해당 수가 사용됨을 나타내는 배열
int arr[10]= {0, };    //출력할 수를 저장하는 배열

void func(int k) //arr[k]의 값을 저장하거나 arr을 출력하도록 하는 함수
{
    if(k>m) //k가 m보다 커서 추가로 저장할 필요가 없는 경우 출력한다.
    {
        for(int i=1; i<=m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = arr[k-1]+1; i<=n; i++) //arr[k-1]보다 큰 수만 저장한다.
    {
        if(!isused[i])
        {
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    func(1);
}