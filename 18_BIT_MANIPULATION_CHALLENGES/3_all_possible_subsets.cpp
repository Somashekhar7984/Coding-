#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
   set = {a,b,c}                            n = no of elements in the given set
                    abc                     no of subsets = 2^n    
   {}           --> 000      ---> 0        
   {c}          --> 001      ---> 1
   {b}          --> 010      ---> 2
   {b,c}        --> 011      ---> 3         here we go from 0 to (2^n) - 1;
   {a}          --> 100      ---> 4
   {a,c}        --> 101      ---> 5
   {a,b}        --> 110      ---> 6
   {a,b,c}      --> 111      ---> 7


*/

void subset(int arr[],int n){
    for(int i = 0;i<(1<<n);i++){
        for(int j = 0;j<n;j++){
            if( i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4};
    subset(arr,4);
    return 0;
}
/*

*/