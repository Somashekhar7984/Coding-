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
        Given an array A of 0s and 1s, we may change up to K values from 0 to 1

        Return length of the longest (contiguous) subarray that contains only 1s.

    Sample test case 1 :
        Input : A = {1,1,1,1,0,0,0,1,1,1,1,0}    k = 2;
        Output : 6
    Explanation:
        {1,1,1,1,0,0,1,1,1,1,1,1}


    Idea :
        --> Find the longest subarray with at most K zeroes

        --> For each A[j] , try to find the longest subarray
        --> if A[i] ~ A[j] has zeroes <= K we continue to increments to j
        --> if A[i] ~ A[j] has zeroes > K , we increment i (as well as j)
*/
/*
    int zero_count = 0;
    int i = 0;
    int ans = 0;
    for(int j = 0;j<A.size();j++){
        if(A[j] == 0){
            zero_count++;
        }
        while(zero_count > K){
            if(A[i] == 0){
                zero_count--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
*/
int main(){
    vector<int> A = {1,1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    int zero_count = 0;
    int i = 0;
    int ans = 0;
    for(int j = 0;j<A.size();j++){
        if(A[j] == 0){
            zero_count++;
        }
        while(zero_count > k){
            if(A[i] == 0){
                zero_count--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}