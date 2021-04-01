#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  list<char> l;
  while(T--){
    string s;
    cin >> s;
    l.clear();
    auto it = l.begin();
    for(int i = 0; i < s.length(); i++){
      if(s[i] == '<'){
        if(it != l.begin()) it--;
      }
      else if(s[i] == '>'){
        if(it != l.end()) it++;
      }
      else if(s[i] == '-'){
        if(it != l.begin()){
          it--;
          it = l.erase(it);
        }
      }
      else l.insert(it, s[i]);
    }
    for (auto a : l) cout << a;
    cout << '\n';
  }
}