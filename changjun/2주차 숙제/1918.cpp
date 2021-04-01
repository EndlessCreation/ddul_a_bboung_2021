#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; //중위 표기식
  stack<char> op; //연산자 스택
  cin >> s;
  for (int i = 0; i < s.length(); i++){
    if (s[i] == '(') op.push(s[i]); //'('가 나온 경우
    else if (s[i] == '*' || s[i] == '/'){ //'*','/'가 나온 경우
      while (!op.empty() && (op.top() == '*' || op.top() == '/')){
        cout << op.top();
        op.pop();
      }
      op.push(s[i]);
    }
    else if (s[i] == '+' || s[i] == '-'){ //'+','-'가 나온 경우
      while (!op.empty() && op.top() != '('){
        cout << op.top();
        op.pop();
      }
    op.push(s[i]);
    }
    else if (s[i] == ')'){  //')'가 나온 경우
      while (!op.empty() && op.top() != '('){
        cout << op.top();
        op.pop();
      }
      op.pop();
    }
    else cout << s[i];  //피연산자가 나온 경우
  }
  while(!op.empty()){ //스택에 남은 연산자 출력
    cout << op.top();
    op.pop();
  }
}