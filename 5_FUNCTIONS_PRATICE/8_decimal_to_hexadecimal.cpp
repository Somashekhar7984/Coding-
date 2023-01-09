#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
// check this problem after strings in C++
string decimal_to_hexadecimal(int n){
    string ans = "";
    int x = 1;
    while(x<=n){
        x = x*16;
    }
    x = x/16;
    while(x>0){
        int last_digit = n/x;
        n = n - last_digit*x;
        x = x/16;

        if(last_digit <= 9){
            ans = ans + to_string(last_digit);
        }
        else{
            char ch = 'A' + last_digit - 10;
            ans = ans + ch;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a decimal number : "<<endl;
    cin>>n;
    string hex = decimal_to_hexadecimal(n);
    cout<<"The hexadecimal form : "<<hex<<endl;
    return 0;
}