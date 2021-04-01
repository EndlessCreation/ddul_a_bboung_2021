// Baekjoon 177298
// 이중 for문으로 돌리면,,,스택을 2개로 만들면,,,,,,시간초과,,,,
// 스택은,,, 선입후출이다,,, 선입후출,,,,,,

// 오큰수를 못찾은 숫자들을 스택에 넣는다?
// 옆에걸 계속 push하다가 만나면 pop해서 그 숫자를 채워넣고, 그다음으로 이동해서 다시 스택에서 뺀다?

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int sequenceNumber;
    cin >> sequenceNumber;
    stack<int> sequence;
    int* sequenceArray = new int[sequenceNumber]();

    if(sequenceNumber==1){ // 입력한 숫자가 1개뿐이면 그냥 -1 출력해주고 끝!
        cout << -1;
        return 0;
    }

    for(int i=0; i<sequenceNumber; i++){
        cin >> sequenceArray[i];
    } // 입력한 숫자 배열에 입력

    sequence.push(0); //어차피 처음은 비어있을테니까 그냥 첫 인덱스는 넣는다
    for(int curIndex=1; curIndex <sequenceNumber; curIndex++) {
        /*cout << "Current Index : "<<curIndex << "\n";
        for(int i=0;i<sequenceNumber;i++){
            cout << sequenceArray[i] << ' ';
        } cout << '\n';*/

        // 스택이 비어있으면 넘어감
        // 현재 인덱스가 스택 맨위보다 크다는 것은 오큰수를 찾았다는 뜻
        while(!sequence.empty() && sequenceArray[curIndex] > sequenceArray[sequence.top()]){
            sequenceArray[sequence.top()] = sequenceArray[curIndex];
            sequence.pop();
        }
        sequence.push(curIndex);
        // 현재 인덱스는 안들어간거기때문에 push 해준다
        // while 문은 거쳤든 안거쳤든 현재 인덱스는 push하게 된다.
        // 거쳤으면 empty이기 때문에 넣어준다 (이 명령으로 스택이 empty가 될일은 없다)

        if(curIndex == sequenceNumber-1){
            // 현재 인덱스가 끝까지 왔는데도 불구하고 아직 스택에 있는 애들은 오큰수를 못찾은것이다
            sequenceArray[curIndex] = -1;
            while(!sequence.empty()){
                sequenceArray[sequence.top()] = sequenceArray[curIndex];
                sequence.pop();
            }
        }
    }
    for(int i=0;i<sequenceNumber;i++){
        cout << sequenceArray[i] << ' ';
    }

}

//
// Created by HUH on 2021-03-30.
//