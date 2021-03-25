#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	int result = A * B * C;
	int num;
	int arr[10] = {};
	while (result > 0) {
		num = result % 10;
		arr[num]++;
		result = result / 10;
	}
	for (int i = 0; i < 10; i++) 
		cout << arr[i] << "\n";
	}
}
