#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

bool isprime(int n){
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int a,b;
    cout<<"Enter two numbers (A<B) : "<<endl;
    cin>>a>>b;
    for(int i = a;i<=b;i++){
        if(isprime(i) == 1){
            cout<<i<<" ";
        }
    }
    return 0;
}