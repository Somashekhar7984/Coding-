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
    Problem:
        Given a array of n numbers. Find the maximum length of bitonic subsequence.
        A subsequence is bitonic if it is strictly increasing and then strictly decreasing 
            or entirely increasing or decreasing

    eg: 
        Input : 
            8
            1 11 2 10 4 5 2 1
        Output :
            6
        Explanation : Maximum length = 1, 2, 4, 5, 2, 1

    Thought Process:
        You know Longest Increasing Subsequence

            Can you code longest Decreasing subsequence from element 'i' to n-1

        At element i,
        1.  You have length of increasing subsequence from 0.
        2.  You have length of decreasing Subsequence from 'i' to n-1.

            Bitonic Subsequence = Forward[i] + backward[i] - 1.

*/
int main(){
    int n = 8;
    vector<int> V = {1,11,2,10,4,5,2,1};
    vector<int> forward(n,1),backward(n,1);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(V[i] > V[j]){
                forward[i] = max(forward[i],1+forward[j]);
            }
        }
    }
    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>i;j--){
            if(V[i] > V[j] ){
                backward[i] = max(backward[i],backward[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,forward[i] + backward[i] - 1);
    }
    cout<<ans<<endl;
    return 0;
}