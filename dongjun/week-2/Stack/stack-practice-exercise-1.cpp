// Beakjoon 10828

#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
int dat[MX];
int pos = 0;

int main(void) {
    int commandNumber;
    cin >> commandNumber;

    for(int i=0; i<commandNumber; i++) {
        string commandText;
        cin >> commandText;

        if(commandText == "push"){
            int inputNum;
            cin >> inputNum;
            dat[pos] = inputNum;
            pos++;
        } else if(commandText == "pop"){
            if(pos==0)
                cout << -1 <<'\n';
            else{
                pos--;
                cout << dat[pos] << '\n';
            }
        } else if(commandText == "size"){
            cout << pos <<'\n';
        } else if(commandText == "empty"){
            if(pos==0)
                cout << 1 <<'\n';
            else
                cout << 0 <<'\n';
        } else if(commandText == "top"){
            if(pos==0)
                cout << -1 <<'\n';
            else{
                cout << dat[pos-1] << '\n';
            }
        }

    }

}

//
// Created by HUH on 2021-03-30.
//

