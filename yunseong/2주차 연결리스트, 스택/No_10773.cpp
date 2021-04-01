#include <iostream>

using namespace std;

typedef struct stack
{
	int *data;
	int stack_size;
};

void InitializeStack(stack* s, int stackMaxSize)
{
	s->data = (int*)calloc(stackMaxSize, sizeof(int));
	s->stack_size = 0;
}

void PushStack(stack* s, int num)
{
	s->data[s->stack_size] = num;
	s->stack_size++;
}

int PopStack(stack* s)
{
	int num = s->data[s->stack_size - 1];
	s->data[s->stack_size - 1] = NULL;
	s->stack_size--;

	return num;
}

int main()
{
	stack s;
	InitializeStack(&s, 100000);		//스택 초기화
	
	int total = 0;
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		
		if (num != 0)
			PushStack(&s, num);
		else
			PopStack(&s);
	}

	for (int i = s.stack_size; i > 0; i--)
		total += PopStack(&s);

	cout << total;
}