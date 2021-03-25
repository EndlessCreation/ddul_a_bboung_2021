#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[]) {

	int answer = 0, count[10] = { 0, };
	std::string roomNum;
	
	std::cin >> roomNum;
	for (int i = 0; i < roomNum.size(); i++) {
		count[roomNum[i] - '0'] += 1;

	}

	count[6] += count[9]+1;
	count[6] /= 2;
	
	
	for (int i = 0; i < 9; i++) {
		if (count[i] > answer)
			answer = count[i];
	}
	std::cout << answer;

	
}
