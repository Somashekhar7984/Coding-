#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

void fibonacci(int n){
    int t1 = 0;
    int t2 = 1;
    int nextTerm;
    for(int i = 0;i<n;i++){
        cout<<t1<<" ";
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return;
}

int main(){
    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    fibonacci(n);
    return 0;
}