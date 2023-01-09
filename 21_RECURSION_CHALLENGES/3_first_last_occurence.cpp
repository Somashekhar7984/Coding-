#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
int first_occur(int arr[],int n,int i,int key){
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    else{
        return first_occur(arr,n,i+1,key);
    }
}
int last_occur(int arr[],int n,int i,int key){
    if(i == -1){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    else{
        return last_occur(arr,n,i-1,key);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int first = first_occur(arr,n,0,key);
    cout<<first<<endl;
    int last = last_occur(arr,n,n-1,key);
    cout<<last<<endl;
    return 0;
}