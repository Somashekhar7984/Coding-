#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        int k;
        if(i%2 == 0){
            k = 0;
        }
        else{
            k = 1;
        }
        for(int j = 0;j<=i;j++){
            if(k == 0){
                k = 1;
                cout<<k<<" ";
            }
            else{
                k = 0;
                cout<<k<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}