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

    for(int i=0; i<sequenceNumber; i++){
        int inputNum;
        cin >> inputNum;
        sequenceArray[i] = inputNum;
    } // 입력한 숫자 배열에 입력

    int curIndex = 0;
    // 이번에는 숫자 그 자체가 아닌 인덱스를 넣어줘서 비교해보기로 한다
    while(curIndex != sequenceNumber){ //현재 인덱스가 끝까지 갈때까지
        /*cout << "Current Index : "<<curIndex << "\n";
        for(int i=0;i<sequenceNumber;i++){
            cout << sequenceArray[i] << ' ';
        } cout << '\n';*/

        if(sequence.empty()){ //비었으면 비교할 숫자가 없기에 현재 인덱스를 넣고 다음으로 넘어감
            sequence.push(curIndex);
            curIndex++;
        }else if(sequenceArray[curIndex] < sequenceArray[sequence.top()]){
            // 현재 스택에 있는게 더 크면, 아직 오른쪽에서 큰수를 못찾은것이기에
            // 현재 인덱스도 넣고 다음으로 넘어감
            sequence.push(curIndex);
            curIndex++;
        }else if(sequenceArray[curIndex] > sequenceArray[sequence.top()]){
            // 현재 스택에 있는것보다 크면 오른쪽 큰수를 찾은것이다
            // 그러면 찾은 오큰수로 덮어씌워주고 덮어씌워준 위치는 pop해서 완료처리!
            sequenceArray[sequence.top()] = sequenceArray[curIndex];
            sequence.pop();
        }
    }

    if(curIndex == sequenceNumber) {
        // 현재 인덱스가 끝까지 왔는데도 불구하고 아직 스택에 있는 애들은 오큰수를 못찾은것이다
        sequenceArray[curIndex] = -1;
        while(!sequence.empty()){
            sequenceArray[sequence.top()] = sequenceArray[curIndex];
            sequence.pop();
        }
    }

    for(int i=0;i<sequenceNumber;i++){
        cout << sequenceArray[i] << ' ';
    }

}

//
// Created by HUH on 2021-03-30.
//