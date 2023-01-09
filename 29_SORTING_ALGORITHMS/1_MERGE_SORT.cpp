#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
                MERGE SORT ALGORITHM
*/
void merge(int arr[],int l,int mid,int r){
    // Making Two temparory arrays for the merging of small arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];

    // Entering the values in the temp arrays 
    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = arr[mid + 1 + i];
    }
    // here a[] , b[] are two sorted arrays that we got during the processes
    // Now we merge these two arrays and store them in the arr[]

    int i = 0; // i is pointer which is used for the traversing of the a[] 
    int j = 0; // j is pointer which is used for the traversing of the b[]
    int k = l;
    
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
/*
                    Time Complexity
            T(n) = 2T(n/2) + n;
            T(n/2) = 2T(n/4) + n/2;
            T(n/4) = 2T(n/8) + n/4;
            T(n/8) = 2T(n/16) + n/8;
            T(n/16) = 2T(n/32) + n/16;
            .
            .
            .
            T(1) = 1

            levels : 
                    n/2^k = 1
                    k = log(n)

            T(n) = n + n + n + n + ........logn times
                 = nlog(n)
*/