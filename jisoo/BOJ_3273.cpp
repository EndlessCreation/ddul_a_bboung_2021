#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[]) {
	
	std::vector<int> number;
	int answer = 0, x = 0, n, temp;
	
	//1.input
	std::cin >> n;
	for (int i = 0;i < n;i++) {
		std::cin >> temp;
		number.push_back(temp);
	}
	std::cin >> x;


	//2.compare
	sort(number.begin(), number.end());
	int head = 0, tail = n - 1;
	while (head < tail) {
		temp = number[head] + number[tail];
		
		if (temp == x) {
			head++;
			tail--;
			answer++;
		}
		else if (temp > x) {
			tail--;
		}
		else {
			head++;
		}

	}
		
	std::cout <<  answer;

}
