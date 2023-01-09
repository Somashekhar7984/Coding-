#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
// Search element in a sorted Rotated array
/*
    We are given an ascending sorted array that has been rotated from a pivot point(Unknown to us) and element X.
    Search for X in the array with Complexity less than that of linear search.

    Eg:
        Original Array = [10,20,30,40,50]
        Rotated Array = [30,40,50,10,20]

        Now Here ==> Divide the array in two parts --> [30,40,50] , [10,20]
        if X = 10 ==> answer(index) = 3
        
        First Step :
            Find Pivot point

         Apply binary search in the left half
         Apply binary search in the right half

        Pivot Point ==> Only element that will be greater than its next element i.e.
                            arr[i] > arr[i+1], i<= n-1     
*/

int search_in_rotated_array(int arr[],int key,int left,int right){
    if(left > right){
        return -1;
    }
    int mid = (left + right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){
        if(key >= arr[left] && key <= arr[mid]){
            return search_in_rotated_array(arr,key,left,mid-1);
        }
        else{
            return search_in_rotated_array(arr,key,mid+1,right);
        }
    }

    if(key >= arr[mid] && key <= arr[right]){
        return search_in_rotated_array(arr,key,mid+1,right);
    }
    return search_in_rotated_array(arr,key,left,mid-1);
}
int main(){
    int arr[] = {6,7,8,9,10,1,2,5};
    int n = 8;
    int key = 8;
    int idx = search_in_rotated_array(arr,key,0,n-1);
    if(idx == -1){
        cout<<"The key doesn't exist"<<endl;
    }
    else{
        cout<<"The key is present at index : "<<idx<<endl;
    }
    return 0;
}