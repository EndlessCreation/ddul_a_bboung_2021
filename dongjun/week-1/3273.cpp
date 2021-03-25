// BaekJoon 3273
// 결국 짝지을수 있는게 있냐고 물어보는것?
// 정렬해서 좌측과 우측을 더해서 기준값보다 크면 우측 기준값을 왼쪽으로.
// 기준값보다 크면 좌측값을 오른쪽으로
// 같으면 count하고 좌측값을 오른쪽으로.

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, X, numberCount=0;
    int number = 0;
    vector<int> numberList;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> number;
        numberList.push_back(number);
    }
    sort(numberList.begin(), numberList.end());
    cin >> X;

    int left=0, right=N-1;
    for(;;){
        //cout << numberList[left] << ' ' << numberList[right] << ' ' << bool(numberList[left]+numberList[right] == X) << "\n";
        if (left >= right)
            break;
        if(numberList[left]+numberList[right] == X){
            numberCount++;
            left++;
        }
        else if(numberList[left] + numberList[right] < X)
            left++;
        else if(numberList[left] + numberList[right] > X ){
            right--;
        }
    }
    cout << numberCount;
}

//
// Created by HUH on 2021-03-25.
//

