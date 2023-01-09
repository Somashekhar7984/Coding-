#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int k = factorial(n);
    cout<<k<<endl;
    return 0;
}