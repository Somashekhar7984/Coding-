#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int fibonacci(int n){
    if(n == 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    cin>>n;
    int nthterm = fibonacci(n);
    cout<<nthterm<<endl;
    return 0;
}