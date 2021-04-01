#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int num; 
	int stack_number = 1; //���ÿ� ���� ����
	stack<int> s;
	string result = "";

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num >= stack_number) { //�Է¹��� ���ڰ� ���� stack_number���� ũ�ų� ������
			while (num + 1 != stack_number) { //�ش� ���ڱ���  stack_number�� �־��ָ� +�� ���
				s.push(stack_number++);
				result += "+\n";
			}
			s.pop();
			result += "-\n"; //�ش� ���ڸ� �����鼭 -�ѹ� ���
		}

		else {
			if (s.top() == num) { //���� �� ���� ���� �Է¹��� ���ڰ� ��ġ�ϸ� �����ϰ� -�� ���
				s.pop();
				result += "-\n";
			}
			else { // ���� �� ���� ���� �Է¹��� ���ڰ� ��ġ���� ������ ������ ���� �� ����.
				result = "NO";
				break;
			}
		}
	}
	cout << result;

	return 0;
}