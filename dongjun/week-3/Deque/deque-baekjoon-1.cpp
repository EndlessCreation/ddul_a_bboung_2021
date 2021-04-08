// baekjoon 5430
// AC는 정수 배열에 연산을 하기 위해 만든 언어
// 두 가지 함수 R(뒤집기)과 D(버리기)

// 함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수
// 배열이 비어있는데 D를 사용한 경우에는 에러가 발생
// 함수는 조합해서 한 번에 사용. "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수

// 덱과 함께 파싱 등등 도 구현해야하는 문제..

#include <bits/stdc++.h>
using namespace std;

int main(void){

    int testCaseNum;
    cin >> testCaseNum;

    while(testCaseNum--) {
        bool reverse = false; // 삭제와 뒤집기 연산만 있는 상태에서 뒤집는다는 건 결국 앞에서 삭제할거냐 뒤에서 삭제할거냐를 나타내는 것
        bool error = false;
        int sequenceCount;
        int tempNum = 0;

        string commandFunction;
        string sequenceNumber;
        deque<int> sequenceDeque; // 배열이 들어갈 덱 선언
        cin >> commandFunction >> sequenceCount >> sequenceNumber; //명령 문자열, 배열 개수, 배열 입력.

        sequenceNumber = sequenceNumber.substr(1, sequenceNumber.size() - 2);
        // 입력한 배열이 [1,2,3,4] 모양으로 있기때문에, 일단 앞뒤 []을 제거

        for (int i = 0; i < sequenceNumber.size(); ++i) {
            // 입력한 배열숫자들을 진짜 int형으로 바꾸기 위한 과정
            if (atoi(sequenceNumber.substr(i, 1).c_str()) != 0 || sequenceNumber.substr(i, 1).compare("0") == 0) {
                // atoi() 함수의 원리는 매개변수로 들어온 문자열을 앞에서 부터 읽어서,
                // "공백" or "숫자가아닌문자" 가 올때까지 숫자로 변환을 해주는 원리
                // i번째 문자 하나를 읽었는데
                // atoi 반환값이 0이 아니면 해당 문자는 숫자이고
                // atoi("0")의 반환값이 0이기때문에 아래 조건문 하나를 더 추가

                // 해당 문자와 매개변수로 "0"을 비교해서 같으면 0을 반환하기에 0이면 해당 문자는 숫자이기때문에
                // 현재 tempNum 변수에 있는 숫자 자리수를 한칸 더 올리고
                tempNum *= 10;
                tempNum += atoi(sequenceNumber.substr(i, 1).c_str());
                // tempNum 변수에 현재 문자의 수를 더한다
            } else {
                sequenceDeque.push_back(tempNum);
                tempNum = 0;
            }
        }
        // 배열 마지막숫자가 두자리수 이면 덱에 추가가 안됐으므로 덱에 추가
        if (tempNum != 0)
            sequenceDeque.push_back(tempNum);


        for (int i = 0; i < commandFunction.size(); i++) {
            if (commandFunction[i] == 'R') {
                reverse = !reverse;
            } else if (commandFunction[i] == 'D') {
                if (sequenceDeque.empty()) { // D를 입력했는데 아무것도 없으면 error 처리하고 반복문 빠져나감
                    error = true;
                    break;
                }

                if (reverse == true) {
                    sequenceDeque.pop_back();
                } else if (reverse == false) {
                    sequenceDeque.pop_front();
                }
            }
        }

        if (error) {
            cout << "error" << '\n';
            continue;
        } //에러 출력처리

        cout << "[";
        if (reverse == false) {
            while (sequenceDeque.size()) {
                cout << sequenceDeque.front();
                sequenceDeque.pop_front();
                if (!sequenceDeque.empty()) { // 뒤에 나올게 있으면 , 출력
                    cout << ",";
                }
            }
        } else if (reverse == true)
            while (sequenceDeque.size()) {
                cout << sequenceDeque.back();
                sequenceDeque.pop_back();
                if (!sequenceDeque.empty()) { // 뒤에 나올게 있으면 , 출력
                    cout << ",";
                }
            }
        cout << "]" << '\n';
    }
}