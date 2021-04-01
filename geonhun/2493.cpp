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

    stack<pair<int,int>> top;   // 현 기준 내 신호를 받을 수 있는 가장 높은 탑
    int n;

    cin >> n;
    for(int i=0; i<n; ++i){
        int tmp;
        cin >> tmp;
        if(top.empty()){ top.push({tmp, i}); cout << "0 ";} // 만약 탑이 비어있다면 push 후 0 출력
        else {                                              // 탑에 뭔가 있다면
            while (!top.empty() && top.top().X < tmp) {     // 나보다 작은 탑이 있다면 pop 해줍니다.
                top.pop();
            }
            if (top.empty())cout << "0 ";                   // 만약 다 pop 되서 탑이 비었다면 0 출력
            else cout << top.top().Y + 1 << ' ';            // 나보다 큰 탑이 있다면 그 친구를 출력
            top.push({tmp, i});                             // 뒤에 나보다 작은 탑이 들어올 수도 있으니 지금 나 넣어주기
        }
    }
}