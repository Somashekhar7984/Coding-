#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int decimal_to_binary(int n){
    int x = 1;
    int ans = 0;
    while(x<=n){
        x = x*2;
    }
    x = x/2;
    while(x>0){
        int last_digit = n/x;
        n = n - (last_digit*x);
        x = x/2;
        ans = ans*10 + last_digit;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a decimal number : "<<endl;
    cin>>n;
    int bin = decimal_to_binary(n);
    cout<<"The binary form is : "<<bin<<endl;
    return 0;
}