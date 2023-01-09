#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        int j;
        for(j = 0;j<n-i-1;j++){
            cout<<"  ";
        }
        int k = i+1;
        for(;j<n;j++){
            cout<<k<<" ";
            k--; 
        }
        k = 2;
        for(;j<=n+i-1;j++){
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}