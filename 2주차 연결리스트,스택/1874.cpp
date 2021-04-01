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
	int stack_number = 1; //스택에 넣을 숫자
	stack<int> s;
	string result = "";

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num >= stack_number) { //입력받은 숫자가 현재 stack_number보다 크거나 같으면
			while (num + 1 != stack_number) { //해당 숫자까지  stack_number를 넣어주며 +를 출력
				s.push(stack_number++);
				result += "+\n";
			}
			s.pop();
			result += "-\n"; //해당 숫자를 꺼내면서 -한번 출력
		}

		else {
			if (s.top() == num) { //스택 맨 위의 값과 입력받은 숫자가 일치하면 제거하고 -를 출력
				s.pop();
				result += "-\n";
			}
			else { // 스택 맨 위의 값과 입력받은 숫자가 일치하지 않으면 수열을 만들 수 없다.
				result = "NO";
				break;
			}
		}
	}
	cout << result;

	return 0;
}