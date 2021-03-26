#include <stdio.h>

// 매 단계 Variable에 대입하기 위한 TF 설정
// T = 1, F = 0으로 두어 T T T --> T T F --> T F T 를 이진법으로 취급하여 매 단계 -1씩 해줌
void minus_B(char* B, int length)
{
	int i = length - 1;
	B[i]--;
	while(i)
	{
		if(B[i] == -1)
		{
			B[i] = 1;
			B[i-1]--;
		}
		else
			break;
		i--;
	}
	
}

// 기본적인 논리 함수
//논리연산 식에서 연산 ¬은 'n'으로, ∧ 는 'a'로 , ∨는 'o'로, →는 'i'로 표기한다.
char logic(char op, char A, char B)
{
	switch(op) {
		case 'a':
			return A && B;
		case 'o':
			return A || B; 
		case 'i':
			return !((A!=B) && (B==0));
		default:
			return B;
	}
}

int main(void) {
	// V = variable, O = Operator, F = 총 개수
	int V, O, F, all = 0;
	// 매 단계 식의 TF 표현 ( 1 = T, 0 = F )
	char B[5] = {1, 1, 1, 1, 1};
	// 대문자 알파벳이 여러번 나오기 때문에 체크하기 위한 배열
	char Check[26] = {0};
	// 부분적인 논리에 대한 결과값, Variable 목록
	char result, Var[5];
	// Expression, TF 표현 배열
	char E[100] = {0}, TF[2] = {'F', 'T'};

	scanf("%d %d %d", &V, &O, &F);
	all = 1 << V;
	
	getchar(); // 버퍼 비워주기
	for(int i = 0, vi = 0; i < F; i++)
	{
		scanf("%c ", E + i);
		char c = E[i];
		if(c < 'a')
		{
			// Variable이 여러번 들어오나 체크 후 Variable 배열에 넣어줌
			if(!Check[c-'A'])
			{
				Var[vi++] = c;
				Check[c-'A']++;
			}
		}
	}
	
	for(int i = 0; i < V; i++)
		printf("%c ",Var[i]);
	printf("RESULT\n\n");
	
	for(int j = 0; j < all; j++)
	{
		// 매 단계 각 Variable에 대한 대입값을 저장하기 위한 배열 , True = 1, False = 0
		char var_TF[26];
		// 부분적인 논리식의 operator
		char op = 0;
		result = 1;
		
		// 단계별 TF를 저장하는 B로부터 대문자 위치에 T/F 저장
		for(int i = 0; i < V; i++)
			var_TF[Var[i]-'A'] = B[i];
		
		for(int i = 0; i < F; i++)
		{
			char c = E[i], buf = 0;
			// not 연산을 계산, 여러번 나올 수 있기 때문에 while
			while(c == 'n')
			{
				buf = !buf;
				i++;
				c = E[i];
			}
			// 대문자가 나올 때 마다 논리식 계산
			// not을 앞에서 미리 처리하기 때문에 무조건 result op V 형태가 나옴
			if(c < 'a')
			{
				result = logic(op, result, buf ^ var_TF[c-'A']);
			}
			else
			{
				op = c;
			}
		}
		
		//각 단계별 결과 출력
		for(int i = 0; i < V; i++)
			printf("%c ", TF[B[i]]);
		printf("%c\n\n", TF[result]);
		
		// TF 저장하는 B 배열에 -1씩 해줌;
		minus_B(B, V);
	}
	return 0;
}
