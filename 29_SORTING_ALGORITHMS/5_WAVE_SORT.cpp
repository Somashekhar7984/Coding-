#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
            WAVE SORT
      arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=arr[5].........

      arr[0]         arr[2]          arr[4]          arr[6]
            \       /       \       /       \       /
              arr[1]          arr[3]          arr[5]
*/
void WAVE_sort(int arr[],int n){
    for(int i = 1;i<n;i+=2){
        if(arr[i] > arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i] > arr[i+1] && i <= n-2){
            swap(arr[i],arr[i+1]);
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
    WAVE_sort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}