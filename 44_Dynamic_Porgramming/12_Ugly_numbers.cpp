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
    Ugly numbers : numbers whose prime factors are 2,3, or 5
        The First 10 ugly numbers are 1,2,3,4,5,6,8,9,10,12
        By Convention, 1 is included
        
        Given a number n, print the n'th Ugly number.

    Sample test case:
        input : n = 15
        output : 24

        input : n = 150
        output : 5832

    brute force:
        n = (2^a)*(3^b)*(5^c)
        1.  Generate all the ugly numbers.
        2.  Sort the ditinct Ugly numbers.
        3.  print the n'th ugly numbers.

    Dyanmic Programming:
        Keep 3 pointers, think of it as merging three sorted lists.

        Assume you have Uk, the k'th ugly number.
        Then Uk+1. must be Min(p1 * 2,p2 * 3,p3 * 5).

        where p1,p2,p3 will be already generated numbers.    
*/
int main(){
    int n = 10;
    int c2(0),c3(0),c5(0);
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        dp[i] = min({2*dp[c2],3*dp[c3],5*dp[c5]});
        if(2*dp[c2] == dp[i]){
            c2++;
        }
        if(3*dp[c3] == dp[i]){
            c3++;
        }
        if(5*dp[c5] == dp[i]){
            c5++;
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}