#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int decimal_to_octal(int n){
    int x = 1;
    int ans = 0;
    while(x<=n){
        x = x*8;
    }
    x = x/8;
    while(x>0){
        int lastdigit = n/x;
        n = n - lastdigit*x;
        x = x/8;
        ans = ans*10 + lastdigit;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a decimal number : "<<endl;
    cin>>n;
    int oct = decimal_to_octal(n);
    cout<<"The octal form : "<<oct<<endl;
    return 0;
}