// BaekJoon 5397
// 맞왜틀.....ㅜㅜㅜㅜㅜㅜㅜㅜ왜틀린거야ㅜㅠㅜㅠㅜㅠㅜㅜㅜ

//맨 오른쪽에 추가하는 커서인 경우 end + 1
//

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int inputStringNum = 0;
    list<char> inputList;

    cin >> inputStringNum;
    for(int i=0; i<inputStringNum; i++) {
        string inputString;
        cin >> inputString;
        list<char> userInputText;
        auto curPoint = userInputText.begin();

        for (char c : inputString){
            if (c == '<') {
                if (curPoint != userInputText.begin())
                    curPoint--;
            } else if (c == '>') {
                if (curPoint != userInputText.end()) // end() : 맨 뒤의 다음 원소를 가리키는 iterator 리턴
                    curPoint++;
            } else if (c == '-') {
                if (curPoint != userInputText.begin()){
                    curPoint--;
                    curPoint = userInputText.erase(curPoint); //erase는 지정한 iterator가 가르키는 원소 삭제후 반환값은 다음원소룰 거루카눈 iterator
                }
            } else {
                userInputText.insert(curPoint, c);// insert(iterator, element) : list의 iterator가 가리키는 위치 앞에 element 추가
            }
        }
        for (auto c : userInputText) cout << c;
    }
}

//
// Created by HUH on 2021-03-29.
//

