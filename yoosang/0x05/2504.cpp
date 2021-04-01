#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack <int> s;
    string str;
    cin>>str;
	int len = str.length();
	int temp = 0;
	int ans = 0;

	for (int i = 0; i < len; i++) {
		//열린 괄호인 경우
		if (str[i] == '(') s.push(-1);
		else if (str[i] == '[') s.push(-3);
		//닫힌 괄호인 경우
		else if (s.empty()){  //1. 닫힌 괄호가 더 많은 경우
			cout<<0;
            return 0;
        }
		else {
			if (s.top() == -1 && str[i] == ')') {
				s.pop();
				s.push(2);
			}
			else if (s.top() == -3 && str[i] == ']') {
				s.pop();
				s.push(3);
			}
			//s.top()이 숫자인 경우 또는 3. 괄호의 짝이 맞지 않는 경우
			else {
				temp = 0;
				while (s.top() != -1 && s.top() != -3) {
					temp += s.top();
					s.pop();

					if (s.empty()){  //1.닫힌 괄호가 더 많은 경우
						cout<<0;
                        return 0;
                    }
				}
				if (s.top() == -1 && str[i] == ')') {
					temp *= 2;
					s.pop();
				}
				else if (s.top() == -3 && str[i] == ']') {
					temp *= 3;
					s.pop();
				}
				else{
					cout<<0;
                    return 0;   //3. 괄호의 짝이 맞지 않는 경우
                }
				s.push(temp);
			}
		}
	}

	while (!s.empty()) {
		if (s.top() == -1 || s.top() == -3){ //2. 열린괄호가 더 많은 경우
			cout<<0;
            return 0;
        }

		ans += s.top();
		s.pop();
	}
    cout<<ans;
}