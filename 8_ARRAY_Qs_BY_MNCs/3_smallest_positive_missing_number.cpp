#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int N = 1e6+2;
    bool check[N];
    for(int i = 0;i<N;i++){
        check[i] = false;
    }
    for(int i = 0;i<n;i++){
        if(arr[i] >= 0){
        check[arr[i]] = true;
        }
    }
    for(int i = 0;i<n;i++){
        if(check[i] == false){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}