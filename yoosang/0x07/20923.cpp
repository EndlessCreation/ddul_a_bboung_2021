#include<bits/stdc++.h>
using namespace std;

deque<int> deck[2], ground[2];

int N, M;

int win_check() {
    if(ground[0].size() && ground[0].front() == 5) return 0;
    if(ground[1].size() && ground[1].front() == 5) return 0;
    if(ground[0].size() && ground[1].size() && ground[0].front() + ground[1].front() == 5) return 1;
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        int a, b; cin >> a >> b;
        deck[0].push_front(a);
        deck[1].push_front(b);
    }
    int turn = 0;
    for(int i=0;i<M;++i) {
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();
        if (deck[turn].empty()) {
            cout << (turn ? "do" : "su") << '\n';
            return 0;
        }
        int w;
        if(ground[0].size() && ground[0].front() == 5) w = 0;
        if(ground[1].size() && ground[1].front() == 5) w = 0;
        if(ground[0].size() && ground[1].size() && ground[0].front() + ground[1].front() == 5) w = 1;
        else w=-1;
        if (w != -1) {
            int l = 1 - w;
            while (ground[l].size()) {
                deck[w].push_back(ground[l].back());
                ground[l].pop_back();
            }
            while (ground[w].size()) {
                deck[w].push_back(ground[w].back());
                ground[w].pop_back();
            }
        }
        turn = 1 - turn;
    }
    if(deck[0].size() > deck[1].size()) cout << "do" << '\n';
    else if(deck[0].size() < deck[1].size()) cout << "su" << '\n';
    else cout << "dosu" << '\n';
    return 0;
}