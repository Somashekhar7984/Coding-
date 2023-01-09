#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int power(int n,int p){
    if(p == 0){
        return 1;
    }
    else{
        return n*power(n,p-1);
    }
}
int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    int k = power(n,p);
    cout<<k<<endl;
    return 0;
}