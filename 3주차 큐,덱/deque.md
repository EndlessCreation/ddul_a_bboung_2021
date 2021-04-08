# **덱(Double Ended Queue)**
    양쪽 끝에서 삽입과 삭제가 전부 가능한 자료구조

## **덱의 성질**
---
1. 원소의 추가가 O(1)
1. 원소의 제거가 O(1)
2. 제일 앞/뒤의 원소 확인이 O(1)
3. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

## **덱의 함수**
---
1.  **push_front 함수** 
   ``` c++
   void push_front(int x){
       dat[--head]=x;
   }
   ```
2. **push_back 함수**
   ```c++
   void push_back(int x){
       dat[tail++]=x;
   }
   ```
3. **pop_front 함수**
   ```c++
   void pop_front(){
       head++;
   }
   ```
4. **pop_back 함수**
   ```c++
   void pop_back(){
       tail--;
   }
   ```
5. **front/back 함수** 
   ```c++
   int front(){
       return dat[head];
   }

   int back(){
       return dat[tail-1];
   }
   ```

## **deque *vs* vector**
---
1. **vector**

    + 일반적인 배열처럼 vector는 개체들을 연속적인 메모리 공간에 저장한다.

    + 즉, iterator 뿐 아니라 position index(operator [])로도 접근이 가능하다는 것이다.

    + vector는 동적으로 확장/축소가 가능한 dynamic array로 구현되어 있다.

  * 강점

    - 개별 원소들을 position index로 접근이 가능하다

    - 원소를 컨테이너의 끝에 삽입/제거 하는 것이 빠르다 
    
    - 어떠한 순서로도 원소들을 순회할 수 있다. 즉, Random access iterating이 가능함. 

    - 일반적으로 vector는 deque에 비해 개별 원소에 대한 접근 속도와 컨테이너의 끝에서 삽입/제거하는 속도가 빠르다.


* 약점

    - 컨테이너의 끝 위치가 아닌 곳에서 삽입/제거 수행시 그 성능은 deque/list에 비해 현저히 떨어진다.
    
* 주의
    - 동적으로 컨테이너의 크기가 확장/축소되는 것이 편하기는 하나, 확장시의 재할당은 비용이 꽤 크다.
     
    - capacity를 확장 시켜줄 수 있는 적절한 크기의 reserve로 인한 메모리 확보가 중요.
---

2. **deque (double ended queue)**

    + deque는 어느 정도 vector와 유사성이 있는 듯하면서도 상당히 많이 다르다고도 할 수 있는 시퀀스 컨테이너다.

    + Random access iterator를 통한 개별 원소에 대한 접근이 가능하다. operator []도 지원된다.
   
    + 컨테이너의 크기가 동적으로 조절되지만, 그 방법은 vector의 그것과 많이 다르다.

* 강점
    - 개별 원소들을 position index로 접근이 가능하다.
     
    - 원소를 컨테이너의 끝 뿐 아니라, 앞에서도 삽입/제거 하는 것이 빠르다.
     
    - 어떠한 순서로도 원소들을 순회할 수 있다.
     
* 약점
   - 컨테이너의 시작 / 끝 위치가 아닌 곳에서 삽입/제거 수행시 그 성능은 list에 비해 현저히 떨어진다.

   - vector의 경우 컨테이너 내부 capacity가 고갈되면 이를 확장하기 위해 전체 메모리 크기만큼 재할당이 발생한다.
    하지만, deque의 경우 일정 크기를 가지는 chunk 단위로 확장되는 방식을 가지고 있다.

* 장점

    - 저장 원소가 많고 메모리 할당량이 큰 경우 vector에 비해 확장 비용이 절감된다.


* 단점

    - 컨테이너 처음부터 끝까지 연속 메모리 공간이 아니므로, vector에서 가능했던 원소들간 포인터 연산이 불가능하다.
 ---