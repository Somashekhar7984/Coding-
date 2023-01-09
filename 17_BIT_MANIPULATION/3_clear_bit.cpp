#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    n = 0101  ---> binary form of 5
    clear bit ==> changing that bit to '0';
    suppose we need to clear bit at position, i = 2
    1<<i == 0100;
    ~0100 = 1011;

        0101 & 1011 = 0001  ==> the bit at position 2 is changed to '0'
*/
int clear_bit(int n,int pos){
    return (n&(~(1<<pos)));
}
int main(){
    cout<<clear_bit(7,2)<<endl;
    return 0;
}