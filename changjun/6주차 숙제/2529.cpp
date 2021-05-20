#include <bits/stdc++.h>
using namespace std;

int k;
char s[10];
bool isused[11];
vector<int> v;
vector<string> ans;

bool check(){   // 부등호 관계 확인
    for(int i = 0; i < k; i++){
        if(s[i] == '<'){
            if(v[i] > v[i + 1]) return false;
        }
        else if(s[i] == '>'){
            if(v[i] < v[i + 1]) return false;
        }
    }
    return true;
}

void dfs(int cur){
    if(cur == k + 1){   // 원하는 자릿수를 찾으면
        if(check()){    // 부등호 관계 확인
            string tmp = "";
            for(int i = 0; i < v.size(); i++){
                tmp += to_string(v[i]);
            }
            ans.push_back(tmp);
        }
        return;
    }
    for(int i = 0; i < 10; i++){    // 자릿수 만들기
        if(!isused[i]){
            v.push_back(i);
            isused[i] = true;
            dfs(cur + 1);
            isused[i] = false;
            v.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for(int i = 0; i < k; i++){ // 부등호 입력
        cin >> s[i];
    }
    dfs(0);
    cout << ans[ans.size() - 1] << "\n";
    cout << ans[0];
}