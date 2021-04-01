#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        list<char> l;
        auto iter = l.end();
        for (auto c : s) {
            if (c == '<') {
                if (iter != l.begin())
                    iter--;
            }
            else if (c == '>') {
                if (iter != l.end())
                    iter++;
            }
            else if (c == '-') {
                if (iter != l.begin()) {
                    iter=l.erase(--iter);
                }
                
            }
            else {
                l.insert(iter, c);
            }
        }
        for (auto c : l)
            cout << c;
        cout << '\n';
    }
    return 0;
}