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
            Longest_Common_Subsequence:
    Problem:
        Given two strings S1 and S2. we need to output length of longest common subsequence.

    Test Case:
        S1 = "RISHABH"
        S2 = "SHUBHI"
            Largest Common Subsequence = "SHBH"
*/
/*
    Brute Force:
        Compute all subsequences of any of the string and check whether it is subsequence of other string also.
        Pick the one with maximum length.

    Efficient Approach:
        Let f(i,j) denotes the length of LCS of S1[0,....i-1] and S2[0,..j-1]

        Two Case Arise:
            1.  S1[i-1] = S2[j-1]
                    f(i,j) = 1 + f(i-1,j-1)
            2.  S1[i-1] != S2[j-1]
                    Further two possiblities.
                        a.  Take S1[i-1] in LCS
                        b.  Take S2[j-1] in LCS
                    f(i,j) = max(f(i-1,j),f(i,j-1));

        Either if we don't take either of them , that case is also included in the above Possibilities.

        Since we can recurrence relation of problems hence if follows optimal substructure Property.

*/
const int N = 1e4+2;
int dp[N][N];
int lcs(string &s1,string &s2,int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(s1[n-1] == s2[m-1]){
        dp[n][m] = 1 + lcs(s1,s2,n-1,m-1);
    }
    else{
        dp[n][m] = max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
    return dp[n][m];
}
int main(){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    cout<<lcs(s1,s2,n,m)<<endl;
    return 0;
}