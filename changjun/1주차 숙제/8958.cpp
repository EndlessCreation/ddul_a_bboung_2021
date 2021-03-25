#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        int result=0;
        int con=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='O'){
                con++;
                result+=con;
            }
            if(s[j]=='X') con=0;
        }
        cout << result << '\n';
    }
}