#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        int j = 0;
        for(j = 0;j<n-i-1;j++){
            cout<<" ";
        }
        while(j<n){
            cout<<"*";
            j++;
        }
        cout<<endl;
    }

    return 0;
}