// BeakJoon 1475
// 방 번호가 주어졌을 때, 필요한 숫자 세트의 개수의 최솟값
// 6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.
// > 6과 9 둘이 합쳐 2개가 한 세트가 된다.
// 중간에 넣은 테스트 코드는 확인해서 빼고 제출한다ㅜㅜ....

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string roomNumber;
    int numberList[9] = {0, };
    cin >> roomNumber;
    for(char number : roomNumber) {
        if (number == '9'){ // 9는 6이랑 같이세는걸로함.
            numberList[6]++;
            continue;
        }
        numberList[(int)number-48]++;
    }
    if(numberList[6] % 2 != 0)
        numberList[6]++;
    numberList[6] /= 2;
    int maxCount=0;
    for(int i=0; i<9; i++){
        if(maxCount<numberList[i])
            maxCount=numberList[i];
    }
    cout << maxCount;
}

//
// Created by HUH on 2021-03-23.
//

