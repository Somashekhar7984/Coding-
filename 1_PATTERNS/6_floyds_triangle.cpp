#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int k = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout<<k+1<<" ";
            k++;
        }
        cout<<endl;
    }
    return 0;
}