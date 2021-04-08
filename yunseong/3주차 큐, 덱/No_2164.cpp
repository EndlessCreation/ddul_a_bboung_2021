#include <iostream>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	head++;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		dat[i] = i+1;

	tail = n;

	while (tail - head != 1)
	{
		pop();
		push(dat[head]);
		pop();
	}

	cout << dat[head];
}