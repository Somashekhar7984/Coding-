#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;
/*
    UNORDERED SET:
        1.  Contains Unique elements
        2.  Implemented using Hashing
        3.  Elements are not in Sorted Order
        4.  Random access is not possible , i.e you cannot get i'th element in O(1)
        5.  Present in #include<unordered_set> header file
*/
int main(){
    unordered_set<int> S;
    S.insert(3);
    S.insert(1);
    S.insert(5);
    S.insert(2);
    for(auto i : S){
        cout<<i<<" ";
    }
    cout<<endl;
    S.erase(2);
    for(auto i : S){
        cout<<i<<" ";
    }
    cout<<endl;
    /*
    Time Complexities:
        1.  Insertion : O(1) in Avg,O(N) in worst case
        2.  Deletion  : O(1) in Avg,O(N) in worst case
        3.  Lower/Upper_bound: NA 
    */
    return 0;
}