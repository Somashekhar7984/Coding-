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
    Minimum no of squares whose sum equals to given number 'n'

        Eg : 26 = 4^2 + 3^2 + 1^2
                = 5^2 + 1^2
                    Minimum no of numbers required = 2
*/
const int N = 1e5+2,MOD = 1e9+7;
int dp[N];

int min_square(int n){
    if(dp[n] != MOD){
        return dp[n];
    }
    if(n == 1 || n == 2 || n == 3 || n == 0){
        return n;
    }
   // int ans = MOD;
    for(int i = 1;i*i<=n;i++){
        //ans = min(ans, 1 + min_square(n - i*i));
        dp[n] = min(dp[n] , 1 + min_square(n - i*i));
    }
    //return ans;
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<N;i++){
        dp[i] = MOD;
    }
    cout<<min_square(n)<<endl;
    return 0;
}