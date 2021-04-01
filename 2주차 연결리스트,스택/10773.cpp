#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	int sum = 0;
	cin >> k;

	stack<int> s;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			sum -= s.top();//맨 위의 수는 합에서 빼야한다.
			s.pop();//맨 위의 수를 제거한다.
		}
		else {
			s.push(num);
			sum += s.top();
		}
	}

	cout << sum << "\n";

	return 0;
}