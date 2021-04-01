#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(0);
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }

    int isPalindrome[2001][2001];
    for(int i=1;i<=n;i++){
        isPalindrome[i][i]=1;
    }
    for(int i=1;i<n;i++){
        if(v[i]==v[i+1])
            isPalindrome[i][i+1]=1;
    }

    for(int gap=2;gap<=n;gap++)
    {
        for(int s_ind=1;s_ind+gap<=n;s_ind++)
        {
            int e_ind=s_ind+gap;
            if(isPalindrome[s_ind+1][e_ind-1]==1&&v[s_ind]==v[e_ind])
                isPalindrome[s_ind][e_ind]=1;
            else
                isPalindrome[s_ind][e_ind]=0;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<isPalindrome[s][e]<<"\n";
    }
}
