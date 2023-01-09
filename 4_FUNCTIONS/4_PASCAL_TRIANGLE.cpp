#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

int factorial(int n){
    int factorial = 1;
    for(int i = 2;i<=n;i++){
        factorial = factorial*i;
    }
    return factorial;
}

int nCr(int n,int r){
    int ans = factorial(n)/(factorial(n-r)*factorial(r));
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout<<nCr(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}