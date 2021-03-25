#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n;

    vector<int> list(n);

    for(int i=0; i<n; ++i){
        cin >> list[i];
    }
    cin >> x;

    sort(list.begin(), list.end());
    int ans=0;
    int start = 0, end = list.size()-1;

    while(start<end){
        if(list[start] + list[end] == x) {start++; ans++;}
        else if (list[start] + list[end] < x){start++;}
        else if (list[start] + list[end] > x){end--;}
    }
    cout<<ans;
}