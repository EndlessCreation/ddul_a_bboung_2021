#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int n,num;
	queue<int> q;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.size() == 0)
				cout << "-1\n";
			else {
			int val = q.front();
			q.pop();
			cout << val << "\n";
			}
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			cout << q.empty() << "\n";
		}
		else if (s == "front") {
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else {
			if (q.size() == 0)
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

}