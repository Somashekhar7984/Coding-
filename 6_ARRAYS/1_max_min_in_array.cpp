#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for(int i = 0;i<n;i++){
        maxNo = max(maxNo,arr[i]);
        // here max(a,b) is a built in function in C++ which gives the max value in 'a' and 'b'
        minNo = min(minNo,arr[i]);
        // here min(a,b) is a built in function in C++ which gives the min value in 'a' and 'b'
    }
    cout<<maxNo<<" "<<minNo<<endl;
    return 0;
}