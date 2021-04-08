#include <iostream>
#include <string>

using namespace std;

const int MX = 3000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int main() {

	string name;
	int n;
	int k;

	int result = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		push(name.length());

		/*
		for (int j = 1; j <= k && i + j <= n; j++)
		{
			if (dat[tail-1] == dat[head - j])
				result++;
		}
		*/
		if (tail - head == k);
		pop();

	}

	cout << result;
}