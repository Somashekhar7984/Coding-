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
    Find the peak element:

        For a given array,find the peak element in the array.Peak element is one which is greater than both,
        left and right neighbours of itself.

    Corner Cases:
        Ascending order : Last element is Peak Element
        Descending Order : First element is Peak element
        For all Element are same : Each element is Peak

    Eg : arr[] = {10,20,15,2,23,90,67}
                    Here the elements 20 (10 < 20 && 20 > 15) , 90 (23 < 90 && 90 > 67) are the peak elements

    Strategy:
        Use Binary searches, analyze indices from 0 to n-1

        Compute mid && for each mid check if arr[mid] is Peak Element or not
            i.e.    arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]

        else if arr[mid - 1] > arr[mid]
                    check left part of peak
        else if arr[mid] < arr[mid + 1]
                    check right part of peak

        eg : arr[] = {1,3,20,4,1,0}
                start = 0 and end = 5;

                mid = (0+5)/2 = 2;
                arr[mid] = 20 --->  (arr[mid] = 20) > (arr[mid-1] = 3) && (arr[mid] = 20) > (arr[mid+1] = 4)                            

                    return mid
*/
int peak_element(int arr[],int low,int high,int n){
    int mid = low + (high - low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid + 1] <= arr[mid])){
        return mid;
    }
    else if (mid > 0 && arr[mid - 1] > arr[mid]){
        return peak_element(arr,low,mid-1,n);
    }
    else{
        return peak_element(arr,mid+1,high,n);
    }
}
int main(){
    int arr[] = {10,20,15,2,23,90,67};
    int n = 7;
    cout<<"The Peak Element index : "<<peak_element(arr,0,n-1,n)<<endl;
    return 0;
}