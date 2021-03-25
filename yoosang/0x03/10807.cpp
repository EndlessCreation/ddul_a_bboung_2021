#include<bits/stdc++.h>
using namespace std;
int main() 
{
	int n, c, cnt=0;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> c;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
			cnt++;
	}
	cout << cnt;
	return 0;
}