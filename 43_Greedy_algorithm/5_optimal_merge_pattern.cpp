#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
/*
    OPTIMAL MERGE PATTERN   
        Problem:
            You are given n files with their Computation times in an array
        Operation:
            Choose/take any two files,add their Computation times and append it to the list of computation times.
            {Cost = Sum of Computation time}
            Do this until we are left with only one file in the array. we have to do this operation such that
            we get minimum cost finally.
    Approach:
        1.  Push all elements to a min_heap
        2.  Take Top elements one by one and add the cost to the answer. 
            Push the merged file to the min_heap.
        3.  When single element remains, output the cost            
*/
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int i = 0;i<n;i++){
        min_heap.push(V[i]);
    }
    int ans = 0;
    while(min_heap.size() > 1){
        int e1 = min_heap.top();
        min_heap.pop();
        int e2 = min_heap.top();
        min_heap.pop();
        ans = ans + e1 + e2;
        min_heap.push(e1+e2);
    }
    cout<<ans<<endl;
    return 0;
}