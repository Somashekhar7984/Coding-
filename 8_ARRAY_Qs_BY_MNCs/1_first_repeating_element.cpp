#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
// This code time complexity is O(n)
// But this has some error in it

/*
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    const int N = 1e6+2;
    int idx[N];
    for(int i = 0;i<N;i++){
        idx[i] = -1;
    }
    int minidx = INT_MAX;

    for(int i = 0;i<n;i++){
        if(idx[arr[i]] != -1){
            minidx = min(minidx,idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
    }
    if(minidx == INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minidx+1<<endl;
    }
    return 0;
}

*/

// This code is of time complexity  ----> O(n^2)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] == arr[j]){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}