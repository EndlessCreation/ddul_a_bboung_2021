#include <iostream>

using namespace std;

typedef struct Node
{
	struct Node *next;
	int data;
};

int main(void)
{
	//���⼭���� ����

	Node *dummy = (Node*)malloc(sizeof(Node));	//ù��° ��带 ����ų ���
	Node *newNode = NULL;						//���� ������� ���
	Node *cur = dummy;							//���� ��� (������ ����� ��ġ)

	int n;
	int k;

	//���⼭���� ����

	cin >> n >> k;

	for(int i =1; i<=n; i++)
	{		
		newNode = new Node();
		newNode->data = i;	
		newNode->next = NULL;					//���ο� ���Ҹ� ����

		cur->next = newNode;					//���� ��带 ������ ���� ����

		if (i == n)
			newNode->next = dummy->next;		//������ n�� ��带 1�� ���� �����Ͽ� ���� ���� ����Ʈ �ϼ�

		cur = newNode;							//���� ��带 ���� ������� ���� ����
	}

	cur = dummy;								//���� ��带 dummy ���� ����

	//������� ���

	cout << "<";

	for (int i = 1; i <= n; i++)
	{
		for(int j = 0; j<k-1; j++)
			cur = cur->next;					//������ ��ġ�� ������ġ�� �̵�

		dummy = cur->next;						//dummy�� ������ ��带 ��´�.
		cout << dummy->data;					//������ data ���

		if (i != n)
			cout << ", ";
		else
			cout << ">";

		cur->next = cur->next->next;			//����
	}
	

	
}