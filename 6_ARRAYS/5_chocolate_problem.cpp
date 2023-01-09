#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of rupees : "<<endl;
    cin>>n;
    int wrappers = n;
    int chocolates = 0;
    int left[n];
    int i = 0;
    while(n>0){
        chocolates = chocolates + wrappers;
        wrappers = (n/3);
        n = n/3;
        left[i] = n%3;
        i++;
    }
    int sum = 0;
    for(int j = 0;j<i;j++){
        sum = sum + left[j];
    }
    chocolates = chocolates + (sum/3);
    cout<<chocolates<<endl;

    return 0;
}