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

int main(){
    set<int> S;
    S.insert(1);
    S.insert(3);
    S.insert(5);

    // lower_bound(val) ==> Returns val if val is present in the containers or next element that is present in the set
    // upper_bound(val) ==> Returns the next element for which the value in the element is > val 
    cout<< *S.lower_bound(2)<<endl; // output : 3
    cout<< *S.lower_bound(3)<<endl; // output : 3
    cout<< *S.upper_bound(5)<<endl; // output : 5
    cout<< (S.upper_bound(5) == S.end()) <<endl;
    return 0;
}