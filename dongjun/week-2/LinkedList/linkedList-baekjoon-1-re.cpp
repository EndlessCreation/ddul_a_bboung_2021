#include <bits/stdc++.h>
using namespace std;

int main(void){
    int testCaseNumber;
    cin >> testCaseNumber;

    for(int i=0; i<testCaseNumber; i++){
        string inputText;
        cin >> inputText;
        list<char> userInputText;
        auto curPoint = userInputText.begin();

        for(char c : inputText) {
            if (c == '<'){
                if (curPoint != userInputText.begin())
                    curPoint--;
            } else if (c == '>'){
                if (curPoint != userInputText.end())
                    curPoint++;
            } else if (c == '-'){
                if (curPoint != userInputText.begin()){ // 맨 앞일 경우 삭제 할 수 없으므로 PASS. 안할경우 런타임에러
                    curPoint--; // 내가 있는 위치에서 앞에걸을 지워야 되므로 curPoint--
                    curPoint = userInputText.erase(curPoint);
                    // erase는 지우고나서 기존에 지웠던 원소 다음 원소를 가르키도록 반환한다
                    // (결국 curPoint는 원래 가르켰던 원소를 그대로 다시 가르키게 되므로 curPoint++를 해줄필요 없음)
                }
            } else {
                userInputText.insert(curPoint, c);
                // curPoint가 가르키고 있는 위치 앞에 insert해주는 것이므로 왼쪽에 insert 해주는것
            }
        }

        for (char c : userInputText)
            cout << c;
        cout << '\n'; // 출력 형식을 잘 지키자 ^__^
    }


}
//
// Created by HUH on 2021-03-30.
//