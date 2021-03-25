#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int cnt=0;
    int arr[2][7]={0};
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int s,y;
        cin>>s>>y;
        arr[s][y]++;
    }
    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=6;j++)
        {
            cnt+=ceil((double)arr[i][j] / k);
        }
    }
    cout<<cnt;
}