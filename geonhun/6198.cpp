#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define X first
#define Y second

int main(){
    // 밑에 이거 두 줄 안써주면 시간 초과 납니다.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> building;
    long long ans = 0;

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;

        while(!building.empty() && building.top()<=tmp)
        {
            building.pop();
        }

        building.push(tmp);
        ans += (long long)building.size()-1;
    }

    cout << ans;
}