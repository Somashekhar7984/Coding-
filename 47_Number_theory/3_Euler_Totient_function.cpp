#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
/*
    Euler Totient Function : 
            No of numbers from 0 to n-1 which are co-prime with n

            n*(1 - (1/p1))*(1 - (1/p2))*(1 - (1/p3))*.....(1 - (1/pk));
            where p1,p2,p3,p4....pk are distinct prime factors of n.
*/
const int N = 1e5+2,MOD = 1e9+7;
int totient[N];

int main(){
    for(int i = 0;i<N;i++){
        totient[i] = i;
    }

    for(int i = 2;i<N;i++){
        if(totient[i] == i){
            for(int j = 2*i ;j<N;j = j+i){
                totient[j] = totient[j]*(i-1);
                totient[j] = totient[j]/i;
            }
            totient[i] = i-1;
        }
    }
    for(int i = 2;i<11;i++){
        cout<<totient[i]<<" ";
    }
    return 0;
}