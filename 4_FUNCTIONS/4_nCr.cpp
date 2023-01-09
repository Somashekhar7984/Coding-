#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

//  nCr = factorial(n)/(factorial(n-r)*factorial(r))

int factorial(int n){
    int factorial = 1;
    for(int i = 2;i<=n;i++){
        factorial = factorial*i;
    }
    return factorial;
}

int main(){
    int n,r;
    cout<<"Enter n and r (n>r) : "<<endl;
    cin>>n>>r;
    int nCr = factorial(n)/(factorial(n-r)*factorial(r));
    cout<<nCr<<endl;
    return 0;
}