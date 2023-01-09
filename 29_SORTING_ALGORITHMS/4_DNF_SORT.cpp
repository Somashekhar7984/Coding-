#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    DNF SORT == DUTCH NATIONAL FLAG SORT(0,1,2 sort)

    there will be three pointers in the algorithm
    1 --> low
    2 --> mid
    3 --> high

    from index 0 to low == zeroes
    from index low to mid = ones
    from index mid to high = UNKNOWN region
    from index high to end of array(size of array) = twos
*/
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void DNF_sort(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    DNF_sort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}