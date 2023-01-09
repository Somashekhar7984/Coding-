#include<iostream>
#include<iomanip>
#include<string>
//   *********************** This code is effecting the harddrive better avoid it in the pc **************
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
            n  == 0101
    suppose we need to update bit at position , i == 1(0001)  to 1;
        First we clear the bit at the given position by clear_bit
             1<<i = 0010;
             ~(1<<i) = ~(0010) = 1101

          0101 & 1101 = 0101;

        Next we set the bit to '1' by using set_bit
             1<<i == 0010
             0101 | 0010 = 0111;         
*/
int update_bit(int n,int pos,int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
}

int main(){
    cout<<update_bit(5,1,1)<<endl;
    return 0;
}