#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    string str;
    cin>>str;
    int temp=0;
    int result=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(')
            s.push(-1);
        else if(str[i]=='[')
            s.push(-3);
        else if(s.empty()) // 닫힌 괄호가 더 많은 경우 종료
            return 0;
        else{   
            if(s.top()==01&&str[i]==')'){
                s.pop();
                s.push(2);
            }
            else if(s.top()==-3&&str[i]==']'){
                s.pop();
                s.push(3);
            }
            else{   //s.top이 양수인 경우, 괄호의 짝이 맞지 않는 경우
                temp=0;
                while(s.top()!=-1&&s.top()!=-3){
                    temp+=s.top();
                    s.pop();

                    if(s.empty())   //닫힌 괄호가 더 많은 경우 종료
                        return 0;
                }
                if(s.top()==-1&&str[i]==')'){
                    temp*=2;
                    s.pop();
                }
                else if(s.top()==-3&&str[i]==']'){
                    temp*=3;
                    s.pop();
                }
                else
                    return 0; //괄호의 짝이 안맞는 경우

                s.push(temp);
            }
        }
    }
    while(!s.empty()){
        if(s.top()==-1||s.top()==-3)    //열린 괄호가 더 많은 경우
            return 0;

        result+=s.top();
        s.pop();
    }
    cout<<result;
}