#include <iostream>
using namespace std;
//모음과 자음의 갯수를 카운트한다.
int cnt1=0;
int cnt2=0;

int L, C;                   //L : 암호 길이, C : 문자 종류 수
int can_use[130] = {0, };   //해당 문자가 사용가능함을 나타내는 배열 0~'a'~'z' 까지
char arr[20]= {'a'-1, };    //출력할 암호를 저장하는 배열

void func(int k) //arr[k]의 값을 저장하거나 arr을 출력하도록 하는 함수
                 //k는 1부터 시작하도록 한다.
{
    if(k>L && cnt1 >=1 && cnt2 >= 2) //k가 L보다 커서 추가로 저장할 필요가 없는 경우 출력한다.
    {
        for(int i=1; i<=L; i++)
            cout << arr[i];
        cout << '\n';
        return;
    }

    for(int i = arr[k-1]+1; i<='z'; i++) //이전 암호보다 사전순으로 나중의 문자만 저장한다.
    {
        if(can_use[i])
        {
            arr[k] = i;
            
            if(i == 'a' || i=='e' || i=='i' || i=='o' || i=='u') cnt1++;
            else cnt2++;    //i가 a~z인지 한번더 확인해 볼 것
            can_use[i] = 0;
            
            func(k+1);

            if(i == 'a' || i=='e' || i=='i' || i=='o' || i=='u') cnt1--;
            else cnt2--;
            can_use[i] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i =0; i<C; i++)
    {
        char input;
        cin >> input;
        can_use[(int)input] = 1;
    }
    func(1);
}