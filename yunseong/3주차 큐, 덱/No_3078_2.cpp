#include <iostream>
#include <string>

using namespace std;

int student[21] = { 0, };					//�̸� ���̿� ���� �л� �� ����

const int MX = 3000005;
int dat[MX];								//���������� �л� �̸��� ���� ����
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void pop() {
	student[dat[head]]--;					//k���� �ָ� ������ ����� �л��̸� pop�ϸ鼭 �� ��󿡼� ����
	head++;
}

int main() {

	string name;
	int name_len;

	int n;
	int k;

	long long result = 0;					//int������ ������ ��� ���� ����

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> name;						//�̸� �Է�
		name_len = name.length();

		result += student[name_len];		//�̸� ���� ���� �л� �� ��ŭ result ����

		push(name_len);						//�Էµ� �л� push
		student[name_len]++;

		if (tail - head == k+1)				//���� �л� �� ���� �������� pop
			pop();
	}

	cout << result;
}