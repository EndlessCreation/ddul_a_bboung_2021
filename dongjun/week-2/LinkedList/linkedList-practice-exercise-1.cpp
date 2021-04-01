// BaekJoon 1406
// 영어 소문자만, 600,000글자 입력가능
// 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우

// L입력시 커서를 왼쪽, R입력시 커서를 오른쪽, B입력시 커서 왼쪽에 있던 문자 삭제
// 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
// P $ > '$'라는 문자를 커서 왼쪽에 추가

// 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때,
// 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오.
// 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치

// 첫째 줄에는 초기에 편집기에 입력되어 있는 문자열, 길이 N, 길이는 100,000을 넘지 않는다.
// 입력할 명령어 개수 M (1 ≤ M ≤ 500,000)
// 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string preString;
    int commandNumber = 0;
    list<char> userInputText;

    cin >> preString >> commandNumber;

    for (char c : preString)
        userInputText.push_back(c);
    auto curPoint = userInputText.end();
    // end() : 맨 뒤의 다음 원소를 가리키는 iterator 리턴

    for(int i=0; i<commandNumber; i++) {
        char command;
        cin >> command;
        if(command == 'P'){
            char inputChar;
            cin >> inputChar;

            userInputText.insert(curPoint, inputChar);
            //cout << "insert:" << inputChar << "\n";
            // 여기에 추가하는 코드 작성
            // insert(iterator, element) : list의 iterator가 가리키는 위치에 element 추가
        }
        else if (command == 'L'){
            if(curPoint != userInputText.begin())
                curPoint--;
            //cout << "L:" << *curPoint <<'\n';
        }
        else if (command == 'D'){
            if(curPoint != userInputText.end())
                curPoint++;
            //cout << "R:" << *curPoint <<'\n';
        }
        else if (command == 'B'){
            //cout << "Delete:" << *curPoint << "\n";
            if (curPoint != userInputText.begin()) {
                curPoint--;
                curPoint = userInputText.erase(curPoint);
            }
            //lt.erase(iter) : iterator가 가리키는 원소를 삭제합니다.
            //- 반환값은 삭제한 원소의 다음 원소를 가리키는 iterator를 반환
            //여기에 삭제하는 코드 작성
        }

    }

    for (auto c : userInputText) cout << c;

}

//
// Created by HUH on 2021-03-28.
//

