#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	queue <int> q;
	for (int i = 1; i <= n; i++) {		//1부터 입력한 숫자까지 카드 생성
		q.push(i);
	}

	while (q.size()!=1) {				
		q.pop();
		if (q.size() == 1) {			//남은 카드가 1개일때 탈출
			break;
		}
		q.push(q.front());		
		q.pop();
	
		
	}
	cout << q.front();
}