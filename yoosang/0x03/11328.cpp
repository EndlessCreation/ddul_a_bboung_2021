#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int arr1[26] = { 0 }, arr2[26] = { 0 };
		int len1 = s1.length();
		int len2 = s2.length();
		for (int i = 0; i < len1; i++)
		{
			arr1[s1[i] - 'a']++;
		}
		for (int i = 0; i < len2; i++)
		{
			arr2[s2[i] - 'a']++;
		}
		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			if (arr1[i] != arr2[i])
				flag = false;
		}
		flag ? cout << "Possible\n" : cout << "Impossible\n";
	}
}