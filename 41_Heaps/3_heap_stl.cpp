#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
        STL in Heaps

        in standard template library(STL) : Max_heap is utilised

        HEAP STL
        1.  Max_heap : priority_queue<int, vector<int>>
        2.  Min_heap : priority_queue<int, vector<int> , greater<int>>

        Push = O(log(n));
        Pop = O(log(n));
        top = O(1);
        size = O(1);
*/

int main(){
    priority_queue<int,vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<endl;
    priority_queue<int , vector<int> ,greater<int>> pq2;
    pq2.push(2);
    pq2.push(1);
    pq2.push(3);

    cout<<pq2.top()<<endl;
    pq2.pop();
    cout<<pq2.top()<<endl;
    return 0;
}