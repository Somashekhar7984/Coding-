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
    Numbers are coming and we have to tell median after each input
    Eg : 10,15,21,30,18,19

    After First Input:
        Sorted : 10
        Median : 10

    After second Input:
        Sorted : 10 , 15
        Median : (10 + 15)/2 = 12.5

    After Third Input:
        Sorted : 10,15,21
        Median : 15

    After Fourth Input:
        Sorted : 10,15,21,30
        Median : (15+21)/2 = 18

    After fiveth Input:
        Sorted : 10,15,18,21,30
        Median : 18

    After Sixth Input:
        Sorted : 10,15,18,19,21,30
        Median : (18+19)/2 = 18.5


    Brute Force : 
        After Every Input, Sort the array (nlog(n)) time
        and then quote the median
            Time Complexity = O((n^2)Log n);

    Optimal Appoarch:
        Using Heaps:
            1.  Keep One Max_heap and One Min_heap
            2.  Partition the array in two Parts

    For eg:
        Before Input (18)

                Top             Top 
        10      15              21     30
            Max_heap            Min_heap

            Now Insert 18
                (Make sure that the difference in size between the two Heaps is <= 1)

        Max_heap:           Min_heap:
            10 15 18            21 30

            if sizes of max heap and min heap are not equal 
                    median = Top of Larger size Heap
            else
                    median = Avg of Top elements of Two Heaps
        
*/
void insert(int x,priority_queue<int,vector<int>,greater<int>> &pq_min_heap,priority_queue<int, vector<int>> &pq_max_heap){
    if(pq_min_heap.size() == pq_max_heap.size()){
        if(pq_max_heap.size() == 0){
            pq_max_heap.push(x);
            return;
        }

        if(x < pq_max_heap.top()){
            pq_max_heap.push(x);
        }
        else{
            pq_min_heap.push(x);
        }
    }
    else{
        // Two Cases Possible
        // Case 1 : Size of max_heap > Size of min_heap
        // Case 2 : Size of min_heap > Size of max_heap

        if(pq_max_heap.size() > pq_min_heap.size()){
            if(x >= pq_max_heap.top()){
                pq_min_heap.push(x);
            }
            else{
                int temp = pq_max_heap.top();
                pq_max_heap.pop();
                pq_min_heap.push(temp);
                pq_max_heap.push(x);
            }
        } 
        else{
            if(x <= pq_min_heap.top()){
                pq_max_heap.push(x);
            }
            else{
                int temp = pq_min_heap.top();
                pq_min_heap.pop();
                pq_max_heap.push(temp);
                pq_min_heap.push(x);
            }
        }
    }
}
double find_median(priority_queue<int,vector<int>, greater<int>> pq_min_heap,priority_queue<int, vector<int>> pq_max_heap){
    if(pq_min_heap.size() == pq_max_heap.size()){
        return ((pq_min_heap.top() + pq_max_heap.top())/2.0);
    }
    else if(pq_max_heap.size() > pq_min_heap.size()){
        return pq_max_heap.top();
    }
    else{
        return pq_min_heap.top();
    }   
}
int main(){
    priority_queue<int,vector<int>, greater<int>> pq_min_heap;
    priority_queue<int, vector<int>> pq_max_heap;

    insert(10,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    insert(15,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    insert(21,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    insert(30,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    insert(18,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    insert(19,pq_min_heap,pq_max_heap);
    cout<<find_median(pq_min_heap,pq_max_heap)<<endl;
    return 0;
}