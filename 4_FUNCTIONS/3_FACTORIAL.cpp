#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int factorial(int n){
    int factorial = 1;
    for(int i = 2;i<=n;i++){
        factorial = factorial * i;
    }
    return factorial;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;
    return 0;
}