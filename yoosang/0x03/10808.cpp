#include<bits/stdc++.h>
using namespace std;
int main() 
{
	string s;
	cin >> s;
	int arr[26] = { 0 };
	for (auto c : s)
	{
		arr[c - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << ' ';
	}
}