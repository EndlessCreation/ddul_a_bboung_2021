#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main(){
    int N;
    cin >> N;
    deque<pair<int, int>> d;
    for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        d.push_back(make_pair(i, n));
    }
    while(!d.empty()){
        cout << d.front().first << ' ';
        int n = d.front().second;
        d.erase(d.begin());
        if(n < 0){
            for(int i = 0; i < abs(n); i++){
                d.insert(d.begin(), d.back());
                d.erase(d.end()-1);
            } 
        }
        else{
            for(int i = 0; i < n-1; i++){
                d.push_back(d.front());
                d.erase(d.begin());
            }
        }
    }
    return 0;
}