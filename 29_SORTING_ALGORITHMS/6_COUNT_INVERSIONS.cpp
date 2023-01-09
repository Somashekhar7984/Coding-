#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
                COUNT INVERSIONS
    problem statements:
            Count the inversions in the given array
            Two elements a[i] and a[j] form an inversion if a[i]>a[j] && i < j
                    3   5   6   9   1   2   7   8
            INVERSIONS : 10
            explanation : (3,1) (3,2) (5,1) (5,2) (6,1) (6,2) (9,1) (9,2) (9,7) (9,8)
*/
/*
    int inv = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(a[i] > a[j]){
                inv++;
            }
        }
    }
    cout<<inv<<endl;
    Time Comlexity = O(n^2)
*/
/*
    we use merge sort procedure for the counting the inversions for optimized code

*/
int merge(int arr[],int low,int mid,int high){
    int inv = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int a[n1];
    int b[n2];
    for(int i = 0;i<n1;i++){
        a[i] = arr[low + i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            inv = inv + n1 - i;
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while(i < n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}
int mergeSort(int arr[],int low,int high){
    int inv = 0;
    if(low < high){
        int mid = low + ((high - low)/2);
        inv += mergeSort(arr,low,mid);
        inv +=mergeSort(arr,mid+1,high);

        inv +=merge(arr,low,mid,high);
    }
    return inv;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int inv = mergeSort(arr,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<inv<<endl;
    return 0;
}