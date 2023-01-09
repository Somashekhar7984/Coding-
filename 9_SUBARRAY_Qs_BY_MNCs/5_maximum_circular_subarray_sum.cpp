#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int kadane(int arr[],int n){
    int currentsum = 0;
    int maxSum = INT_MIN;
    for(int i = 0;i<n;i++){
        currentsum += arr[i];
        if(currentsum < 0){
            currentsum = 0;
        }
        maxSum = max(maxSum,currentsum);
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int wrapSum ;
    int nonWrapSum;
    
    nonWrapSum = kadane(arr,n);

    int total_sum = 0;
    for(int i = 0;i<n;i++){
        total_sum = total_sum + arr[i];
        arr[i] = (-1)*arr[i];
    }

    wrapSum = total_sum + kadane(arr,n);

    cout<<max(wrapSum,nonWrapSum)<<endl;
    return 0;
}