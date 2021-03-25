// BeakJoon 13300
// 남학생은 남학생끼리, 여학생은 여학생끼리
// 같은 학년끼리
// 학생 수 N, 한 방에 배정할 수 있는 최대 인원 수 K
// 성별 S와 학년 Y(1 ≤ Y ≤ 6)가 공백으로 분리되어 주어진다. 성별 S는 여학생 0, 남학생 1

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K, S, Y;
    cin >> N >> K;
    int boyCount[6] = {0, };
    int girlCount[6] = {0, };
    for(int i=0; i<N; i++) {
        cin >> S >> Y;
        if(S==0) {
            girlCount[Y-1]++;
        }
        else if(S==1) {
            boyCount[Y-1]++;
        }
    }

    int roomCount = 0;
    for(int i=0; i<6; i++){
        roomCount += boyCount[i] / K;
        if(boyCount[i] % K !=0 )
            roomCount++;
        roomCount += girlCount[i] / K;
        if(girlCount[i] % K !=0 )
            roomCount++;
    }
    cout << roomCount;
}

//
// Created by HUH on 2021-03-23.
//

