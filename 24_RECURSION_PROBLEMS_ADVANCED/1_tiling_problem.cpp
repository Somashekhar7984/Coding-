#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
Given a "2xn" board and tiles of size "2x1" , count the number of ways to tile the board using these tiles
*/
int no_of_ways(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    return no_of_ways(n-1) + no_of_ways(n-2);
}
int main(){
    int n = 4;
    cout<<no_of_ways(n);
    return 0;
}