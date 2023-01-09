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
    Sets are Two Types:
        1.  Ordered Sets        ==> Either Ascending Order or Descending Order
        2.  Unordered Sets      ==> Without any order

    Ordered Sets:
    1.  Contains Unique Elements
    2.  Implemented using Balanced BST
    3.  Elements are in sorted order
    4.  Random access is not possible ,
                i.e you cannot get i'th element in O(1)/O(log N)
    5.  Present in header file #include<set>   
*/
int main(){
    //Code for insertion and Printing
    set<int> S;

    // Inserting the elements
    S.insert(1);
    S.insert(2);
    S.insert(2);
    S.insert(3);

    // Printing the element in the set
    for(auto i : S){        // Here the 'i' represents the elements in the set
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i = S.begin();i != S.end();i++){       // Here the 'i' is the pointer of elements in the set
        cout<<*i<<" ";  // Since 'i' is a pointer ==> *i is a value in the pointer
    }
    cout<<endl;

    // To Print in Reverse
    for(auto i = S.rbegin();i != S.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    // Size of the set
    cout<<S.size()<<endl;

    // Code - Custom Operator
    set<int,greater<int>> s1;   // Now the insertion will be in such way that the order will be descending order
    s1.insert(1);
    s1.insert(2);
    s1.insert(2);
    s1.insert(3);
    for(auto i = s1.begin();i != s1.end();i++){
        cout<<*i<<" ";
    } 
    cout<<endl;
    return 0;
}