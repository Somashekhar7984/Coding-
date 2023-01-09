#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// Finding prime factors of a number
/*
    first prime factor of a number n
    eg :- n = 20
        20 ----> 10 ----> 5 ----> 1
            2        2        5

*/

void primeFactor(int n){
    int spf[100] = {0};
    for(int i = 2;i<=n;i++){
        spf[i] = i;
    }
    for(int i = 2;i<=n;i++){
        if(spf[i] == i){
            for(int j = i*i ;j<=n;j+=i){
                if(spf[j] ==j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n != 1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}
int main(){
    int n;
    cin>>n;
    primeFactor(n);
    return 0;
}