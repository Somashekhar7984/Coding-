#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
// Time Complexity ---> O(n^3)
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int sum = 0;
            for(int k = i;k<=j;k++){
                sum = sum + arr[k];
            }
            if(sum>maxSum){
                maxSum = sum;
            }
        }
    }
    cout<<maxSum<<endl;
    return 0;
}