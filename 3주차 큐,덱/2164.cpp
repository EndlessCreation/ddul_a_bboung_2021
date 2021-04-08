#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	queue <int> q;
	for (int i = 1; i <= n; i++) {		//1���� �Է��� ���ڱ��� ī�� ����
		q.push(i);
	}

	while (q.size()!=1) {				
		q.pop();
		if (q.size() == 1) {			//���� ī�尡 1���϶� Ż��
			break;
		}
		q.push(q.front());		
		q.pop();
	
		
	}
	cout << q.front();
}