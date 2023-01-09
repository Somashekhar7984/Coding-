#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter a binary number : "<<endl;
    cin>>n;
    int i = 0;
    int dec = 0;
    while(n>0){
        int digit = n%10;
        dec = dec + digit*pow(2,i);
        n = n/10;
        i++;
    }
    cout<<dec<<endl;
    return 0;
}