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
    S.insert(22);
S.insert(3);
S.insert(31);
S.insert(8);
    S.insert(2);
    for(auto i = S.begin();i != S.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // Erase ==> Removes the element from the set
    S.erase(34);
    for(auto i = S.begin();i != S.end();i++){
        cout<<*i<<" ";
    }
    return 0;
}