#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
    Problem:
        Given is an array with n elements that represents n positions along in a straight line.
        Find K elements such that the minimum distance between any 2 elements is the maximum possible     
*/
// Work on this problem again
bool is_feasible(int mid,int arr[],int n,int k){
    int pos = arr[0];
    int elements = 1;
    for(int i = 0;i<n;i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            elements++;
            if(elements == k){
                return true;
            }
        }
    }
    return false;
}
int Largest_minimum_distance(int arr[],int n,int k){
    sort(arr,arr+n);

    int result = -1;
    int left = 1;
    int right = arr[n-1];
    while(left < right){
        int mid = (left + right)/2;
        
        if(is_feasible(mid,arr,n,k)){
            result = max(result,mid);
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return result;
}
int main(){
    int arr[] = {1,2,8,4,9};
    int k = 3;
    cout<<Largest_minimum_distance(arr,5,k)<<endl;

    return 0;
}