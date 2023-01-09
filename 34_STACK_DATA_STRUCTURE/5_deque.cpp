#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
//                  Sliding window maximum Using Deque  (Doublt ended queue)

/*
                    Stack                           Queue
        1. LIFO                             1. FIFO
        2. Push and pop from the end        2. Insert and delete from the start

        DEQUE:      ===>    DOUBLY ENDED QUEUE
            1. push and pop from the end
            2. insert and delete from the start
            3. Header file : <deque>
*/
int main(){
    deque<int> dq;
                    // deque : EMPTY
    dq.push_back(1);    // deque : 1
    dq.push_back(2);    // deque : 1 2
    dq.push_front(3);   // deque : 3 1 2
    dq.push_front(4);   // deque : 4 3 1 2

    for(auto i : dq){
        cout<<i<<" ";
    }
    cout<<endl;
    dq.pop_back();      // deque : 4 3 1
    dq.pop_front();     // deque : 3 1
    for(auto i : dq){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<dq.size()<<endl;
    return 0;
}