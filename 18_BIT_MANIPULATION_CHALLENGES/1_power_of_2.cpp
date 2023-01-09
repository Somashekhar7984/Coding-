#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

// write a program to check if a given number is power of 2
/*
   one possible idea : repeatedly divide the number by 2
                       if last number is 1 it is not a power of 2
                       else   it is a power of 2 
*/
/*
    Using Bit Manipulation
    n = 6 = (0110)
    n - 1 = 5 = (0101)
    now let's see the value of n & n-1 == 0110 & 0101 = 0100 -->4
    n = 8 = (1000)
    n-1 = 7 = (0111)
    n & n-1 = (1000) & (0111) = 0000 --->0
*/

int main(){
    int n;
    cin>>n;
    int res = (n)&(n-1);
    if(res == 0){
        cout<<"Power of 2"<<endl;
    }
    else{
        cout<<"Not a Power of 2"<<endl;
    }
    return 0;
}