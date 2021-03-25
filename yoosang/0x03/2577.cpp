#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int arr[10] = { 0 };
	for (int i = a * b * c; i > 0; i /= 10)
	{
		arr[i % 10]++;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
}