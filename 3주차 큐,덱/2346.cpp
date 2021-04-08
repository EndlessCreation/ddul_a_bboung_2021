#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);			
	cin.tie(0);							

	int n;
	cin >> n;
	deque <pair<int,int>> dq;
	

	for (int i = 1; i <= n; i++) {		//ǳ�� �����
		int num;						
		cin >> num;						  	
		dq.push_back({ i,num });
	}

	int idx = dq.front().first;			//1�� ǳ���� ���� ����
	int val = dq.front().second;

	while (1) {
		cout << idx << ' ';
		if (dq.size()==1) break;		//ǳ���� 1���� ���������� �ݺ�
		dq.pop_front();					//�� ���� ǳ�� �Ͷ߸���
																								 //ǳ���� ��ȣ    1 2 3  4  5
		if (val > 0) {					//���̿� ���� ���ڰ� 0���� Ŭ��							���̿� ���� ����  3 2 1 -3 -1
			for (int i = 1; i < val; i++) {
				dq.push_back({ dq.front().first, dq.front().second });
				dq.pop_front();
			
			}
		}
		else {							//���̿� ���� ���ڰ� 0���� ������
			for (int i = 0; i < -val; i++) {
				dq.push_front({ dq.back().first, dq.back().second });
				dq.pop_back();
				
			}
		}								
		idx = dq.front().first;			//�� ���� ǳ�� ���� ����
		val = dq.front().second;
		
	}
	
}