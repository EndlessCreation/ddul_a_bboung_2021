#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0, j = v.size() - 1;
    int total = 2e9;

    pair<int, int> result;

    while (i < j) {
        int a = v[i]; int b = v[j];
        if (abs(a + b) < total) {
            total = abs(a + b);
            result.first = v[i]; result.second = v[j];
        }

        if (a + b < 0) { i++; }
        else { j--; }
    }
    cout << result.first << " " << result.second << "\n"; return 0;
}