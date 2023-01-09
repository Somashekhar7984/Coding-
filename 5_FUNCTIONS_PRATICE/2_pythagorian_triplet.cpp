#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

int max(int a,int b,int c){
    if(a>b && a>c){
        return a;
    }
    else if(b>c){
        return b;
    }
    else{
        return c;
    }
}

bool check(int a,int b,int c){
    int x = max(a,b,c);

    if(x == a){
        int k = b*b + c*c;
        if(x*x == k){
            return true;
        }
    }

    if(x == b){
        int k = a*a + c*c;
        if(x*x == k){
            return true;
        }
    }

    if(x == c){
        int k = a*a + b*b;
        if(x*x == k){
            return true;
        }
    }
    return false;
}

int main(){
    int a,b,c;
    cout<<"Enter the sides of the triangle"<<endl;
    cin>>a>>b>>c;
    if(check(a,b,c)){
        cout<<"Pythagorian Triplet"<<endl;
    }
    else{
        cout<<"Not a Pythagorian Triplet"<<endl;
    }
    return 0;
}