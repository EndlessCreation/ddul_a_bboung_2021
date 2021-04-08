#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    queue<int> q;   // 현재 줄
    stack<int> s;   // 설 공간
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		q.push(n);
	}
	int order = 1;  // 순서 체크
	while(!q.empty()){
		int num = q.front();
		if(num == order){   // 알맞게 줄에 서있을 경우
			order++;
			q.pop();
		}
		else{   // 줄의 순서가 꼬인 경우 
			if(!s.empty() && s.top() == order){ // 설 공간에 알맞는 순서로 있을 경우
				s.pop();
				order++;
			}
			else{
				s.push(num);
				q.pop();
			}
		}
	}
    bool ans = true;
	while(!s.empty()){  // 순서대로 서 있는지 체크
		int num = s.top();
		s.pop();
		if(num != order){
			ans = false;
		}
		order++;
	}
	if(ans) cout << "Nice";
    else cout << "Sad";
}