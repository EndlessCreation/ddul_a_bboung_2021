// baekjoon 5567
// 내 친구 = 거리 1, 친구의 친구 = 거리 2
// 시작점은 1로 고정
// 나를 기준으로 내 친구들을 먼저 거리에 넣고 다음으로 내 친구들의 친구를 조사한다

#include <bits/stdc++.h>
using namespace std;

int dist[502];
int main(void){
    int alumniNumber, friendListNumber, friendNumber = 0;
    fill(dist, dist+502, -1);
    map<int, vector<int>> vectorM; // 파이썬의 딕셔너리처럼 하나의 키에 여러개의 값을 가지게 하고싶어 사용
    queue<int> Q;
    cin >> alumniNumber >> friendListNumber;
    for(int i=0;i<friendListNumber; i++){
        int number1, number2;
        cin >> number1 >> number2;
        vectorM[number1].push_back(number2); // 하나의 관계가 주어지면 둘은 서로 친구관계이기 때문에 두 사람모두 관계에 서로가 친구라는걸 넣어줘야함
        vectorM[number2].push_back(number1);
    }

    dist[1] = 0; // 시작점이 1이므로 해당 지점은 거리가 0
    Q.push(1); // 시작점을 큐에 넣음
    while(!Q.empty()){
        int cur = Q.front(); Q.pop(); // 현재 방문한곳을 큐에서 빼낸다
        for(int i=0;i<vectorM[cur].size(); i++){
            int myFriend = vectorM[cur][i]; // 현재 친구의 친구를 담아온다
            if(dist[myFriend] != -1) continue; // -1이 아니면 방문한적 있는것이기 때문에 넘어감
            dist[myFriend] = dist[cur] + 1; // 친구거리를 계산한다
            if(dist[myFriend] > 2) continue;
            Q.push(myFriend); // 다음 방문할 친구를 목록에 넣는다
            friendNumber++;
        }
    }
    cout << friendNumber;
}

//
// Created by HUH on 2021-05-05.
//

