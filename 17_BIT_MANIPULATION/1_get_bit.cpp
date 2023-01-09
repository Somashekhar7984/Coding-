#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
        n = 0101 --> binary form of 5
        n                0    1    0    1
        position         3    2    1    0

        suppose we need to get bit at position, i = 2
                i ==  0010 // binary form
                1<<i  = 0100;
         0101 & 0100 = 0100  

         if n & (1<<i) != 0 , then the bit is 1       

*/
int get_bit(int n,int i){
    return (n&(1<<i) != 0);
}

int main(){
    cout<<get_bit(5,2)<<endl;
    return 0;
}