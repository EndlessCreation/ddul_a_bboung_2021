#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    list<int> l;
    for(int i=1;i<=n;i++)
    {
        l.push_back(i);
    }
    auto iter = l.begin();
    while(l.size()>1){
        iter=l.begin();
        iter=l.erase(iter);
        l.push_back(*iter);
        iter=l.erase(iter);
    }
    cout<<*iter;
}