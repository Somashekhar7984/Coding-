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
    Nth Fibonacci Number:

        Fibonacci Sequence : 0 , 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 ............
        fib[n] = fib[n-1] + fib[n-2];
*/
/*
    Optimal Subtructure:
        In Introduction, we saw its Overlapping subproblem Property.

    Time Complexity(without DP) ==> O(2^n)
    Time Complexity(with DP)    ==> O(n)    // With Some Extra Space    
*/
int fib(int n){
    // For the bigger values like 1000 or above 
    // This Function throws segmentation fault
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
// Here Some Storage is used to save the time( Decrese Time Complexity to O(n) )
const int N = 1e5+2;
int dp[N];
int optimal_fib(int n){
    if(dp[n] != -1){
        return dp[n];
    }
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    dp[n] = optimal_fib(n-1) + optimal_fib(n-2);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    //cout<<fib(n)<<endl;
    for(int i = 0;i<N;i++){
        dp[i] = -1;
    }
    cout<<optimal_fib(n)<<endl;
    return 0;
}