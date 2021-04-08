#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);			
	cin.tie(0);							

	int n;
	cin >> n;
	deque <pair<int,int>> dq;
	

	for (int i = 1; i <= n; i++) {		//풍선 만들기
		int num;						
		cin >> num;						  	
		dq.push_back({ i,num });
	}

	int idx = dq.front().first;			//1번 풍선의 정보 저장
	int val = dq.front().second;

	while (1) {
		cout << idx << ' ';
		if (dq.size()==1) break;		//풍선이 1개가 남을때까지 반복
		dq.pop_front();					//맨 앞의 풍선 터뜨리기
																								 //풍선의 번호    1 2 3  4  5
		if (val > 0) {					//종이에 적힌 숫자가 0보다 클때							종이에 적힌 숫자  3 2 1 -3 -1
			for (int i = 1; i < val; i++) {
				dq.push_back({ dq.front().first, dq.front().second });
				dq.pop_front();
			
			}
		}
		else {							//종이에 적힌 숫자가 0보다 작을때
			for (int i = 0; i < -val; i++) {
				dq.push_front({ dq.back().first, dq.back().second });
				dq.pop_back();
				
			}
		}								
		idx = dq.front().first;			//맨 앞의 풍선 정보 저장
		val = dq.front().second;
		
	}
	
}