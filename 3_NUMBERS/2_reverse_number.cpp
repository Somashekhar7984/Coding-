#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int rev = 0;
    while(n>0){
        rev = rev*10 + n%10;  // n%10 gives the last digit of the number 
        n = n/10;
    }
    cout<<rev<<endl;
    return 0;
}