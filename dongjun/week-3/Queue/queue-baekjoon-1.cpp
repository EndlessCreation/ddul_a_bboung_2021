// Baekjoon 1966
// FIFO을 따르는 문제.

// 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인
// 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치
// 현재 문서가 가장 높으면 가장 먼저 인쇄
// 중요도가 높은 순서대로 인쇄하라는 뜻 아닌가?

#include <bits/stdc++.h>
using namespace std;

int printOrder(queue<pair<int, int>>printDocumentQueue, priority_queue<int> priorityDocumentQueue, int findPosition) {
    int count = 0;
    while(!printDocumentQueue.empty()){
        int docPriority = printDocumentQueue.front().first;
        int docIndex = printDocumentQueue.front().second;
        printDocumentQueue.pop();
        if(docPriority == priorityDocumentQueue.top()){
            priorityDocumentQueue.pop();
            count++;
            if(docIndex == findPosition)
                return count;
        } else{
            printDocumentQueue.push({docPriority, docIndex});
        }

    }

    return 0;
}

int main(void) {
    int testCaseNum;
    cin >> testCaseNum;

    for(int i=0; i<testCaseNum; i++) {
        queue<pair<int,int>> printDocumentQueue;
        priority_queue<int> priorityDocumentQueue;
        int queueLength, findPosition;
        int inputNum;
        cin >> queueLength >> findPosition;

        if(queueLength == 1){
            cin >> inputNum;
            cout << 1 << '\n';
            continue;
        } else{
            for(int documentIndex=0;documentIndex<queueLength;documentIndex++){
                cin >> inputNum;
                pair<int,int> document = make_pair(inputNum, documentIndex); //(우선순위, 인덱스)
                printDocumentQueue.push(document);
                priorityDocumentQueue.push(inputNum);
            }
            cout << printOrder(printDocumentQueue,priorityDocumentQueue, findPosition)<< '\n';
        }

    }
}