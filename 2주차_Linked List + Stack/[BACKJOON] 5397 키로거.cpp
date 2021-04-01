#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	int N; //입력받을 String 줄 수
	char c = 0; // 임시 캐릭터 변수
	
	scanf("%d", &N);
	
	getchar(); // 버퍼 비우기
	for(int i = 0; i < N; i++)
	{
		list<char> str; // 출력할 string list
		list<char>::iterator cursor = str.end();
		
		// 캐릭터 하나씩 받아서 처리하는 식으로 해결
		while(1)
		{
			scanf("%c", &c);

			// 개행 시 한줄입력 끝 : 반복문 종료
			if(c == '\n')
				break;
			// '<' 입력 시 iterator 한칸 전으로
			if(c == '<')
			{
				if(cursor != str.begin())
					cursor--;
			}
			// '-' 입력 시 iterator에 해당하는 요소 삭제
			// 주의사항 : list.erase()는 iterator를 해제하고 다음 iterator를 반환하기 때문에 다시 대입해줘야함
			else if(c == '-')
			{
				if(cursor != str.begin())
					cursor = str.erase(--cursor);
			}
			// '>' 입력 시 iterator 한칸 후로
			else if(c == '>')
			{
				if(cursor != str.end())
					cursor++;
			}
			// 나머지 상황은 해당 iterator에 캐릭터 삽입
			else
			{
				str.insert(cursor,c);
			}
		}
		
		// 범위 기반 for 문으로 결과 문자열 출력
		for (char k : str)
			printf("%c", k);
		printf("\n");
	}

	return 0;
}