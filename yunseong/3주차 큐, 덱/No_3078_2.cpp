#include <iostream>
#include <string>

using namespace std;

int student[21] = { 0, };					//이름 길이에 따른 학생 수 저장

const int MX = 3000005;
int dat[MX];								//성적순으로 학생 이름의 길이 저장
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	student[dat[head]]--;					//k보다 멀리 떨어진 등수의 학생이면 pop하면서 비교 대상에서 제외
	head++;
}

int main() {

	string name;
	int name_len;

	int n;
	int k;

	long long result = 0;					//int형으로 선언할 경우 문제 오답

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> name;						//이름 입력
		name_len = name.length();

		result += student[name_len];		//이름 길이 같은 학생 수 만큼 result 증가

		push(name_len);						//입력된 학생 push
		student[name_len]++;

		if (tail - head == k+1)				//비교할 학생 수 보다 많아지면 pop
			pop();
	}

	cout << result;
}