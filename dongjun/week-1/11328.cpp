// BaekJoon 11328
// 두 개의 문자열에 대해, 2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 얻어질 수 있는지 판단
// 이중 for문을 돌아야되나,, 각 알파벳들이 쓰인 숫자가 같은지 보라는 의미 같은데..

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);

    int testCaseN;
    cin >> testCaseN;
    string word1;
    string word2;
    int word1Count[26] = {0, };
    int word2Count[26] = {0, };

    for(int i=0; i<testCaseN; i++) {
        cin >> word1 >> word2;

        for(int j=0; j<word1.length(); j++){
            word1Count[(int) word1[j]-97]++;
            word2Count[(int) word2[j]-97]++;
        }

        for(int k=0; k<26; k++) {
            if(word1Count[k] != word2Count[k]) {
                cout << "Impossible" << "\n";
                break;
            }

            if(k == 25)
                cout << "Possible" << "\n";
        }

        for(int k=0; k<26; k++){
            word1Count[k]=0;
            word2Count[k]=0;
        }

    }


}
//
// Created by HUH on 2021-03-22.
//