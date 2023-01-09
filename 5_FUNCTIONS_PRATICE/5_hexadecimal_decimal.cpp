#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int hexadecimal_to_decimal(string n){
    int ans = 0;
    int x = 1;
    int s = n.size();
    for(int i = s-1;i>=0;i--){
        if(n[i] >= '0' && n[i] <='9'){
            ans = ans + x*(n[i] - '0');
        }
        else if(n[i] >='A' && n[i] <= 'F'){
            ans = ans + x*(n[i] - 'A' + 10);
        }
        x = x*16;
    }
    return ans;
}

int main(){
    string n;
    cout<<"Enter a hexadecimal number : "<<endl;
    cin>>n;
    int ans = hexadecimal_to_decimal(n);
    cout<<ans<<endl;
    return 0;
}