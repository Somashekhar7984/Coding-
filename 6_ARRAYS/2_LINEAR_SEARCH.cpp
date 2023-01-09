#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int linear_search(int arr[],int n,int key){
    for(int i = 0;i<n;i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}
// Time complexity is ----->  O(n) 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int index = linear_search(arr,n,key);
    cout<<index<<endl;

    return 0;
}