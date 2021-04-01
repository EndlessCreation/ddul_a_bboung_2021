// Baekjoon 17298
// 크기가 N인 수열 A = A1, A2, ..., AN
// 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)
// Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미 > 기준점의 오른쪽으로 가면서 기준보다 큰수를 만나면 그 수 출력
// 없는 경우 오큰수는 -1

// 꺼내면서 배열로 관리할까...스택쓰는게 좋을거같은데...
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int sequenceNumber;
    cin >> sequenceNumber;

    stack<int> sequence;
    stack<int> sequenceReverse;
    int* outNumList = new int[sequenceNumber]();
    outNumList[0] = -1;

    int curPoint = 0;

    for(int i=0;i<sequenceNumber;i++){
        int inputNum;
        cin >> inputNum;
        sequence.push(inputNum);
    } // 스택에 입력한 숫자 push

    for(int index=0;index<sequenceNumber;index++){
        int currentNum = sequence.top();
        int tmpNumIndex = -1;
        stack<int> tmpStack; //sequenceReverse 스택에서 임시로 꺼낵 스택을 잠시 저장할 스택.
        for(int i=0; i<index; i++){ // 현재 sequence스택에서 가장 위에 해당 하는 원소와 꺼내진 원소들 중 순서대로 꺼내면서 큰 원소가 몇번째인지 비교
            int tmpNum = sequenceReverse.top(); // 현재 Reverse 스택에서 가장 위에 해당하는 원소 확인
            tmpNumIndex = i; // Reverse 스택에서 꺼내면서 비교하고 다시 비교가 끝나면 원래대로 집어넣을 것이기 때문에 현재 Reverse에서 꺼낸게 몇개 인지 저장
            if(currentNum < tmpNum){
                outNumList[index] = tmpNum; //배열로 저장하여 출력할 예정
                break;
            } else if(i == index-1) { // 주어진 순열 끝까지 갔는데도 못찾았다면 오른쪽에 더 큰수가 없는것이므로 -1 저장
                outNumList[index] = -1;
                break;
            }
            tmpStack.push(sequenceReverse.top()); // 아직 못찾았으니까 다시 Reverse스택에서 꺼내서 tmpStack에 넣기
            sequenceReverse.pop();
        }

        for(int i=0; i<tmpNumIndex;i++){ // Reverse 스택에서 임시로 꺼낸 숫자들을 다시 Reverse에 원래대로 집어 넣음
            sequenceReverse.push(tmpStack.top());
            tmpStack.pop();
        }
        sequenceReverse.push(sequence.top()); // Reverse를 Sequence에서 꺼낸 순서대로 넣어준 다음에 현재 꺼낸 원소를 넣어줘서 기존 Sequence와 반대로 되게 함.
        sequence.pop();
    }

    for(int i=sequenceNumber-1;i>=0;i--){
        cout << outNumList[i] << ' ';
    }

}

//
// Created by HUH on 2021-03-30.
//

