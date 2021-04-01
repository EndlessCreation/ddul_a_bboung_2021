#include<bits/stdc++.h>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    list<int> l;
    for (int i = 1; i <= n;i++)
    {
        l.push_back(i);
    }
    auto iter = l.begin();
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (iter == l.end())
                iter = l.begin();
            iter++;
            if (iter == l.end())
                iter = l.begin();
        }
        v.push_back(*iter);
        iter = l.erase(iter);
    }
    cout << '<';
    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << ", ";
    cout << v[v.size() - 1] << '>';
    return 0;
}