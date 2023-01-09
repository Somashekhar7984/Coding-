#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//                      MAX SUM SUBARRAY OF SIZE K && SUM < X
/*
    For Given array and integers K & X, find the maximum sum subarray of size K and having sum less than X
    Approach 1:
        Compute sum of all possible subarrays size K
        and check the sums with X ==> return the final result

        Time Complexity = O(n*K)

    Approach 2:
        Silding Window Approach

        1.  Calculate sum of first K elements
        2.  Initialise ans with this sum
        3.  Iterate over the rest of the arr
            Keep Adding one element in sum && Removing one from start
            Compare new sum with ans in each iteration.

            Time Complexity = O(n)            
*/
void max_subarray_sum(int arr[],int n,int k,int X){
    int sum = 0;
    int ans = 0;
    for(int i = 0;i<k;i++){
        sum = sum + arr[i];
    }
    if(sum < X){
        ans = sum;
    }
    for(int i = k;i<n;i++){
        sum = sum - arr[i-k] + arr[i];
        if(sum < X){
            ans = max(ans,sum);
        }
    }
    cout<<"The maximum sum of subarray (<X) : "<<ans<<endl;
}
int main(){
    int arr[] = {7,5,4,6,8,9};
    int k = 3;
    int X = 20;
    int n = 6;
    max_subarray_sum(arr,n,k,X);
    return 0;
}