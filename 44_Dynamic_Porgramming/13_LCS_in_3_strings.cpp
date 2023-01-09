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
#include<cstring>
using namespace std;
/*
    LCS = Longest Common Subsequence in 3 strings.

    print the length of LCS of 3 strings.

    Sample test case
    Input:
        GHQWNV
        SJNSDGH
        CPGMAH
    output:
        2       (GH)

    Constraints:
        the length of string is : <= 200
*/
/*
    Recurrence

    if(s[i-1] == s[j-1] && s2[j-1] == s3[k-1]){
        return 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    else{
        int l = LCS(s1,s2,s3,i-1,j,k);
        int r = LCS(s1,s2,s3,i,j-1,k);
        int p = LCS(s1,s2,s3,i,j,k-1);    

        return max({p,l,r});        
    }
*/

int dp[205][205][205];

int LCS(string &s1,string &s2,string &s3,int i,int j,int k){
    if(i == 0 || j == 0 || k == 0){
        return 0;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        return dp[i][j][k] =  1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    else{
        int l = LCS(s1,s2,s3,i-1,j,k);
        int r = LCS(s1,s2,s3,i,j-1,k);
        int p = LCS(s1,s2,s3,i,j,k-1);    

        return max({p,l,r});        
    }
}
int main(){

    memset(dp,-1,sizeof(dp));
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    string s3;
    cin>>s3;

    cout<<LCS(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;
    return 0;
}