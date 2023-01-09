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
    Given an array of items with their {weight,value,and a knapsack(bori)} with weight W.
    Find the maximum value of items that can be stolen and put into knapsack
        Note : We either take tha item or leave the item

        Eg: Value       60  100  150
            Weight      15   30   40

                W = 50 Kg
            Possible Combinations that we can steal
                {15,30} ,   {40}
          value = 160        150

          ans = 160

    Note : it is important to note that we cannot apply greedy techinque here as items are indivisible

    Way of Thinking:
        We iterate from left to right. For each item we have 2 Choices
            1. Take it = remaining capacity of knapsack
            2. Not take it = Capacity remains same.

    Let,
        f(n,W) = denotes the maximum value of items
        we can pick till item n and current capacity of knapsack w

        f(n,W) = max(f(n = 1,w),f(n-1,w - weight[n] + value)) + value[n] ==> Optimal Substructure Property     
*/
/*
    Optimal Solutions (using Dynamic Programming)

        Approach 1 (Memoization)
            1.  write the recursive solution
            2.  Memoize it

        Approach 2 (Tabulation)
            1.  For every time , Compute the answer for every weight from 0 - W
            2.  Use the recurrence of taking and taking
                    dp[n][w] = max(dp[n-1][w],dp[n-1][w - wt[n]]) + val[n];
            3.  Output answer
*/

const int N = 1e3 + 2,MOD = 1e9+7;
int val[N],wt[N];


int dp[N][N];   // Memotise
int knapsack(int n,int w){
    if(w == 0){
        return 0;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1] > w){
        dp[n][w] = knapsack(n-1,w);
        return dp[n][w];
    }

    dp[n][w] = max(knapsack(n-1,w) , knapsack(n-1,w-wt[n-1]) + val[n-1]);
    return dp[n][w];
}
int main(){
    int n;
    cin>>n;

    // Intialise dp to -1

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        cin>>wt[i];
    }
    for(int i = 0;i<n;i++){
        cin>>val[i];
    }

    int w;
    cin>>w;

    cout<<knapsack(n,w)<<endl;
    return 0;
}