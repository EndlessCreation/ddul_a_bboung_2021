#include <iostream>
using namespace std;

int n, m;       //총 n개의 수 중 m개의 수를 골라 출력
int arr[10];    //지금까지 고른 수를 기록하는 배열
bool isused[10];//해당 수를 사용했음을 나타내는 배열

void func(int k)
{
    if(k==m)    //총 m개의 수를 모두 골랐을 경우 결과를 출력하고 함수를 종료한다.
    {
        for(int i= 0; i<m; i++)
            cout<<arr[i]<< ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!isused[i])      //사용하지 않은 수를 발견하면
        {
            arr[k] = i;     //해당 수를 arr에 넣고
            isused[i] = 1;  //사용했음을 표시한다.
            func(k+1);      //다음 칸을 채우기 위해 새롭게 func호출
            isused[i] = 0;  //해당 수의 사용이 끝나면 사용중이지 않음을 표시한다.
        }
    }
}

int main(void)
{
    cin >> n >> m;
    func(0);
}