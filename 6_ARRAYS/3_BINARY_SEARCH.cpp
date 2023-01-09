#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

// Time complexity ----> O(log n)

// Recursive way of binary search
int binary_search(int arr[],int low,int high,int key){
    if(low>high){
        return -1;
    }
    int mid = (low + high)/2;
    if(key<arr[mid]){
        return binary_search(arr,low,mid-1,key);
    }
    else if(key>arr[mid]){
        return binary_search(arr,mid+1,high,key);
    }
    else{
        return mid;
    }
}
// iterative way of binary search
int binary_search_1(int arr[],int n,int key){
    int start = 0;
    int end = n;
    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else if(arr[mid]<key){
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int index = binary_search(arr,0,n-1,key);
    cout<<index;
    return 0;
}