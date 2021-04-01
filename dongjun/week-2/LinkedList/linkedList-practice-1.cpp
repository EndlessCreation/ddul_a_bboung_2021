#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1; //사용되지 않은 인덱스로, 사용후 1씩 증가
// 0번지는 항상 맨 앞의 원소로 고정시켜놓은 야매리스트

void insert(int addr, int num){ // addr은 추가하고자 하는 원소의 앞의 원소의 주소
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    // unused 원소의 데이터값, 앞/뒷주소 세팅 (nxt[addr]가 -1이여도 상관없다)

    if(nxt[addr] != -1){ // 맨뒤에 추가하는 경우에는 삽입할 원소뒤가 없으므로
        pre[nxt[addr]] = unused; // 삽입할 위치 뒤에 위치한 원소(nxt[addr] 가 가르키는 pre(기존 addr였던것) 를 unused로 바꿈)
    }
    nxt[addr] = unused; // 삽입할 위치 앞에 위치한 원소가 가르키는 다음 주소 값 변경
    unused++;
}

void erase(int addr){
    // 삭제할 addr는 어차피 주소도, 데이터도 아무것도 안쓰니까 굳이 건드릴 필요도 없음
    // 앞에 위치한 원소가 nxt 가르키는 것을 뒤에 위치한 원소로
    // 뒤에 위치한 원소(nxt[addr]) 가 pre 가르키는 것을 앞에 위치한 원소(pre[addr])로
    nxt[pre[addr]] = nxt[addr]; // pre[addr]가 -1이 될일은 없다 (항상 0번지가 존재하므로)
    if (nxt[addr] != -1){ //맨 뒤의 원소를 삭제하는 경우 삭제할 원소 뒤에 원소가 없으므로
        pre[nxt[addr]] = pre[addr];
    }
}

void traverse(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test(){
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test(){
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}

//
// Created by HUH on 2021-03-28.
//

