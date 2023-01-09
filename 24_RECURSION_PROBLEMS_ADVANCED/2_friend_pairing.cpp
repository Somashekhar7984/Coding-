#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int friend_pairing(int n){
    if(n == 0 || n == 1 || n == 2){ // n = 0 if there are no one in the group then friend_pairing = 0 (n)
        return n;                   // n = 1 if there is one person in the group then he/she will be single  return 1(n)
    }                               // n = 2 if there are two persons 
                                    /*  one way ----> both are single
                                        other way --> they are in a pair
                                        total no of ways = 2  (n)   */    
    return (friend_pairing(n-1) + (n-1)*(friend_pairing(n-2)));
}

int main(){
    int n = 5;
    cout<<friend_pairing(n);
    return 0;
}