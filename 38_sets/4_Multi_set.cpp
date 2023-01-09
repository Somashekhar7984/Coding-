#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;
/*
    Multi Set  :
        1.  Can contain Duplicates
        2.  Implemented using balanced BST
        3.  Elements are in sorted order
        4.  Random access is not possible, 
                i.e you cannot get i'th element in O(1)/O(Log N)
        5.  Present in #include<set> header file
*/
int main(){
    multiset<int> st;
    st.insert(1);
    st.insert(3);
    st.insert(3);
    st.insert(3);
    st.insert(5);
    for(auto i : st){
        cout<<i<<" ";
    }
    cout<<endl;

    st.erase(3);    // ERASE ==> Deletes the All Occurences of 3
    for(auto i : st){
        cout<<i<<" ";
    }
    cout<<endl;
    // st.find ==> returns the pointer of the given element
    st.erase(st.find(3));   // Deletes the single occurence of 3
    for(auto i : st){
        cout<<i<<" ";
    }
    cout<<endl;
    /*
        Time Complexities:
            1.  Insertion : O(Log N)
            2.  Deletion : O(Log N)
            3.  Lower/Upper_bound : O(Log N)
    */
    return 0;
}