#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    Meaning of set is to change the bit to '1';
    Meaning of unset is to change the bit to '0';

            n =  0101 // binary form of 5;
    suppose we need to set bit at position, i = 1
            1<<i = 0010
            0101 | 0010 = 0111        


*/
int set_bit(int n,int pos){
    return (n | (1<<pos));
}
int main(){
    cout<<set_bit(5,1)<<endl;
    return 0;
}