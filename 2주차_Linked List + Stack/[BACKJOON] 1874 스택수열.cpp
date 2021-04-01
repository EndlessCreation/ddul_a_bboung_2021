#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, t, ri=0; // 최대값, 임시 변수, 결과 문자열 인덱스
	char r[400001] = {0}; // 결과 문자열
	
	vector<int> stack; // stack으로 사용
	vector<int> result; // 입력받은 결과
	vector<int> myresult; // 내가 계산한 결과
	
	scanf("%d", &N);
	
	// 결과값 입력받아서 push
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &t);
		result.push_back(t);
	}
	
	int now = 0; // 결과의 현재 인덱스
	int start = 1; // 반복문 시작 인덱스
	
	//끝까지 탐색할 때 까지 반복
	while(now < N)
	{
		int buf_result = result[now]; // 호출 여러번이라 할당받음;

		// 각 위치 결과가 시작위치 값보다 크거나 같으면 가능
		// 각 위치 결과가 시작위치 값보다 작으면 실패 --> NO 출력하러 반복문 종료
		if(start <= buf_result)
		{
			//해당 결과값이 나올 때 까지 stack에 push
			//출력배열에 +\n 추가
			for(int i = start; i <= buf_result; i++)
			{
				stack.push_back(i);
				r[ri++] = '+';
				r[ri++] = '\n';
			}
		}
		else
			break;
		
		// start부터 now위치의 결과값 까지 push하니까, 다음 탐색할 시작점은 결과값 + 1
		start = buf_result + 1;
		
		//now 위치의 결과값과 스택의 top부분의 값이 같으면 myresult에 해당 값 push 후 result에서 제거
		//출력배열에 -\n 추가
		//now 위치의 결과값은 성공했으므로 다음 위치로 +1;
		while(now < N && result[now] == stack.back())
		{
			myresult.push_back(stack.back());
			stack.pop_back();
			r[ri++] = '-';
			r[ri++] = '\n';
			now++;
		}
	}
	
	//vector의 경우 == 으로 원소의 수와 값이 같으면 참
	//굳이 검사 안하고도 할 수 있지만 넣어봄
	if(myresult == result)
		puts(r);
	else
		printf("NO\n");

	return 0;
}