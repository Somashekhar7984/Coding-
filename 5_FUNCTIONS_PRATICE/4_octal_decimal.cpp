#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
// ***************octal to decimal***********
int main(){
    int n;
    cout<<"Enter a octal number :"<<endl;
    cin>>n;
    int i = 0;
    int dec = 0;
    while(n>0){
        int digit = n%10;
        dec = dec + digit*pow(8,i);
        i++;
        n = n/10;
    }
    cout<<dec<<endl;
    return 0;
}