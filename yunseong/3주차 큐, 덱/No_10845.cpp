#include <iostream>
#include <string>

using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	if (head == tail)
		cout << "-1\n";
	else
	{
		cout << dat[head] << "\n";
		head++;
	}

}

void size() {
	cout << tail - head << "\n";
}

void empty() {
	if (head == tail)
		cout << "1\n";
	else
		cout << "0\n";
}

void front() {
	if (head == tail)
		cout << "-1\n";
	else
		cout << dat[head] << "\n";
}

void back() {
	if(head == tail)
		cout << "-1\n";
	else
		cout << dat[tail-1] << "\n";
}

int main() {
	string cmd;
	int input;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			cin >> input;
			push(input);
		}

		if (cmd == "pop")
			pop();
		if (cmd == "size")
			size();
		if (cmd == "empty")
			empty();
		if (cmd == "front")
			front();
		if (cmd == "back")
			back();
	}
}