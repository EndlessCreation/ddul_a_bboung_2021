#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int arr[10]={0};
    for(auto c : s)
    {
        arr[c-'0']++;
    }
    int num=0;
    for(int i=0;i<10;i++)
        if(i!=9&&i!=6)
            num=max(num,arr[i]);
    cout << max(num , (arr[6]+arr[9]+1)/2);
}