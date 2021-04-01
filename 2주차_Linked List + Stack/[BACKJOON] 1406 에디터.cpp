#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int N; //입력받을 줄 수
	char c, n; // 임시 캐릭터, 줄바꿈/띄어쓰기 구분 캐릭터
	
	list<char> str;
	list<char>::iterator cursor;
	
	// 문장 입력받아 리스트로 넣음
	while(1)
	{
		scanf("%c", &c);
		
		if(c == '\n')
			break;
			
		str.push_back(c);
	}
	
	scanf("%d", &N);
	// iterator 맨 뒤로
	cursor = str.end();
	
	getchar();
	for(int i = 0; i < N; i++)
	{
		//scanf 입력 시 c만 입력받으면 개행문자나 띄어쓰기 때문에 오류가 생겨서 그냥 입력받아서 처리
		scanf("%c%c", &c, &n);
		if(n == '\n')
		{
			// 'L' 문자 입력 시 커서 왼쪽으로
			if(c == 'L') 
			{
				if(cursor != str.begin())
					cursor--;
			}
			// 'D' 입력 시 커서 오른쪽으로
			else if(c == 'D')
			{
				if(cursor != str.end())
					cursor++;
			}
			// 'B' 입력 시 커서 위치 요소 삭제
			else if(c == 'B')
			{
				if(cursor != str.begin())
					cursor = str.erase(--cursor);
			}
		}
		// P의 경우 P 띄어쓰기 넣을 문자라서 else로 처리
		else
		{
			// 위와 마찬가지 이유로 n으로 개행문자 입력 받아버림
			scanf("%c%c", &c, &n);
			str.insert(cursor,c);
		}
	}
	
	for (char k : str)
		printf("%c", k);
	printf("\n");

	return 0;
}