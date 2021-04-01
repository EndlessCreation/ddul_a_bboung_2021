#include <iostream>

using namespace std;

typedef struct Node
{
	struct Node *next;
	int data;
};

int main(void)
{
	//여기서부터 선언

	Node *dummy = (Node*)malloc(sizeof(Node));	//첫번째 노드를 가리킬 노드
	Node *newNode = NULL;						//새로 만들어질 노드
	Node *cur = dummy;							//현재 노드 (연산이 수행될 위치)

	int n;
	int k;

	//여기서부터 저장

	cin >> n >> k;

	for(int i =1; i<=n; i++)
	{		
		newNode = new Node();
		newNode->data = i;	
		newNode->next = NULL;					//새로운 원소를 생성

		cur->next = newNode;					//현재 노드를 생성된 노드와 연결

		if (i == n)
			newNode->next = dummy->next;		//마지막 n번 노드를 1번 노드와 연결하여 원형 연결 리스트 완성

		cur = newNode;							//현재 노드를 새로 만들어진 노드로 변경
	}

	cur = dummy;								//현재 노드를 dummy 노드로 변경

	//여기부터 출력

	cout << "<";

	for (int i = 1; i <= n; i++)
	{
		for(int j = 0; j<k-1; j++)
			cur = cur->next;					//삭제할 위치의 이전위치로 이동

		dummy = cur->next;						//dummy에 삭제할 노드를 담는다.
		cout << dummy->data;					//삭제할 data 출력

		if (i != n)
			cout << ", ";
		else
			cout << ">";

		cur->next = cur->next->next;			//삭제
	}
	

	
}