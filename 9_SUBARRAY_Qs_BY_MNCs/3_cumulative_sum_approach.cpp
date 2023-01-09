#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

/*
    arr                         -1   4   7   2
    cumulative sum array        -1   3   10  12
*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int cumulative_sum[n+1];
    cumulative_sum[0] = 0;
    for(int i = 1;i<=n;i++){
        cumulative_sum[i] = cumulative_sum[i-1] + arr[i-1];
    }
    int maxSum = INT_MIN;

    for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 0;j<i;j++){
            sum = cumulative_sum[i] - cumulative_sum[j];
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}