#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
// Time Complexity --->O(n)
bool pairSum(int arr[],int n,int given_sum){
    // before using this function 
    // You should have sorted array

    int low = 0;
    int high = n-1;
    for(int i = 0;low<high;i++){   // The condition in the loop can { low < high } -->better one or { i < n } -->might be ineffective
        if(arr[low] + arr[high] == given_sum){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low] + arr[high] < given_sum){
            low++;
        }
        else{
            high--;
        }
    }

    return false;
}

int main(){
    int n;
    cin>>n;
    int given_sum;
    cin>>given_sum;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }


    if(pairSum(arr,n,given_sum)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
// Time Complexity ----> O(n^2)
    // for(int i = 0;i<n-1;i++){
    //     for(int j = i+1;j<n;j++){
    //         if(arr[i] + arr[j] == given_sum){
    //             cout<<i<<" "<<j<<endl;
    //             cout<<"True"<<endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout<<"False"<<endl;
    return 0;
}