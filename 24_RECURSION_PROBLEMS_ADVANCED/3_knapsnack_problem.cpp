#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int knapsnack(int value[],int wt[],int n,int W){
    if(n == 0 || W == 0){
        return 0;
    }
    if(wt[n-1] > W){
        return knapsnack(value,wt,n-1,W);
    }
    return max(knapsnack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsnack(value,wt,n-1,W));
}

int main(){
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;
    cout<<knapsnack(value,wt,3,W);
    return 0;
}