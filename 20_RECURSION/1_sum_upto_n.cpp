#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
int sum(int n){
    if(n == 1){
        return 1;
    }
    else{
        return (n + sum(n-1));
    }
}
int main(){
    int n;
    cin>>n;
    int total = sum(n);
    cout<<total<<endl;
    return 0;
}