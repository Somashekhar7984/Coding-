#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

// Armstrong number
// 153    ---->   1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153


int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    int Original_n = n;
    int sum = 0;
    while(n>0){
        int last_digit = n%10;
        sum = sum + pow(last_digit,3);
        n = n/10;
    }
    if(sum == Original_n){
        cout<<"Armstrong Number "<<endl;
    }
    else{
        cout<<"Not a armstrong number"<<endl;
    }
    return 0;
}