#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int arr[26] = {};
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

}