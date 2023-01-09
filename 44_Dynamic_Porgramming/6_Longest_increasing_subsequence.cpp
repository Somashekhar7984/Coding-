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
    Longest Incresing Subsequence:
        Problem : You are given an array.Find the length of longest increasing subsequence.

        subarray: Continuous block of elements.
        Subsequence : Part of the array in order. It may or may not be continuous.

        Every subarray is a subsequence but not every subsequence is not a subarray.

        Example:
            1 4 2 5 3
                Longest increasing subsequence : {1 , 4 , 5}, {1 , 2 , 3}
                    Answer : 3
        
        we define:
          LIS(i) = length of longest increasing subsequence ending at i'th element.
            Therefore, LIS(i) depends on LIS(k) , where 0 < k < i-1

            if(a[i] > a[k]){
                LIS(i) = max(LIS(i),1 + LIS(k));
            }
    Approach : (Using Tabulation)
    1.  Make a dp array and initialis all the dp(i) by 1.
        {Since single element is also an LIS}
    2.  For every i from left to right , iterate from j = 0 to j = i -1

*/
const int N = 1e5+2, MOD = 1e9+7;
int dp[N];
int LIS(vector<int> &V,int n){
    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = 1;// single element is also LIS
    for(int i = 0;i<n;i++){
        if(V[n] > V[i]){
            dp[n] = max(dp[n],1 + LIS(V,i));
        }
    }
    return dp[n];
}
int main(){
    for(int i = 0;i<N;i++){
        dp[i] = -1;
    }
    int n;
    cin>>n;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }
    cout<<LIS(V,n-1)<<endl;
    return 0;
}