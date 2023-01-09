#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
            COUNT SORT
    1. Find the count of every element in the array
    2. Calculate the position of each element in sorted array

    eg : array ==  1 3 2 3 4 1 6 4 3
    count array ===> size of count array = max element in the given array
    (max element in the given array == 6)
    => count array size = 6 + 1 = 7
    count array --> contains the occurence of the elements

    count array              0    2   1   3   2   0   1
                             0    1   2   3   4   5   6 
    cumilative count array   0    2   3   6   8   8   9

*/
void count_sort(int arr[],int n){
    int k = 0; // For the max element in the array
    for(int i = 0;i<n;i++){
        k = max(k,arr[i]);
    }
    int count[10] = {0};
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i = 1;i<=k;i++){
        count[i] = count[i] + count[i-1];
    }
    int output[n];
    for(int i = 0;i<n;i++){
        output[--count[arr[i]]] = arr[i];
    }
    for(int i = 0;i<n;i++){
        arr[i] = output[i];
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    count_sort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}