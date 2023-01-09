#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    given an array nums of distinct integers return all possible permuatations.
    you can return the answer in any order
    sample test case : 
            [1,2,3]
    output :
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
    sample test case :
            [0,1]
    output : 
        0 1
        1 0                   

*/
void permute(int arr[],int low,int high,int size){
    // base case
    if(low == high){
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i = low;i<=high;i++){\
            // swaping is done
            swap(arr[low],arr[i]);
            // Recursive calls
            permute(arr,low+1,high,size);
            // back tracking
            swap(arr[low],arr[i]);
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
    cout<<endl;
    permute(arr,0,n-1,n);

    return 0;
}