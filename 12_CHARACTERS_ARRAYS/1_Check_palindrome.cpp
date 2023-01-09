#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;

    bool check = 1;
    for(int i = 0;i<n;i++){
        if(arr[i] != arr[n-1-i]){
            check = 0;
        }
    }
    if(check == 0){
        cout<<"Not a palindrome"<<endl;
    }
    else{
        cout<<"Palindrome"<<endl;
    }
    return 0;
}