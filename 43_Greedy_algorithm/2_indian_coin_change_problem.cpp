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
    Problem : you are fiven an array Denominations and a value of X.
    You need to find the minimum number of coins required to make value X;

        Note : We have infinite supply of each coin;

        Example :   1 2 5 10 20 50 100 200 500 2000

            388 = 200 + 100 + 50 + 20 + 10 + 5 + 2 + 1 
*/
/*
    Approach:
        1.  Start from the largest value , till we can include it take it.
        2.  Else move on the smaller value
*/
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    // Vector of Denominations
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }

    int X;
    cout<<"Enter the amount : "<<endl;
    cin>>X;

    sort(V.begin(),V.end(),greater<int>());

    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = ans + (X/V[i]);
        X = X - ((X/V[i])*V[i]);
    }
    cout<<"The minimum no of Coins : "<<ans<<endl;
    return 0;
}