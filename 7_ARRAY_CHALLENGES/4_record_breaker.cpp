#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
int maxi(int arr[],int n){
    int max = arr[0];
    for(int i = 0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int no_of_record_breaking_days = 0;
    if(arr[0] > arr[1]){
        no_of_record_breaking_days = 1;
    }
    for(int i = 1;i<n;i++){
        if(arr[i] > arr[i-1] && arr[i]>arr[i+1]){
            no_of_record_breaking_days ++;
        }
        else if(arr[i] > maxi(arr,i-1)){
            no_of_record_breaking_days++;
        }
        else{
            continue;
        }
    }
    cout<<no_of_record_breaking_days<<endl;


    return 0;
}