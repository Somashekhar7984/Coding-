#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// **************** Euclid Algorithm ****************
/*
    Ex :  24 , 42
        24 = 2 x 2 x 2 x 3
        42 = 2 x 3 x 7
    now consider 42 - 24 = 18       42 % 24 = 18
                 24 - 18 = 6        24 % 18 = 6
                 18 - 6 = 12        18 % 6 = 0
                 12 - 6 = 6
                 6 - 6 = 0         
*/
int gcd(int a,int b){
    while(b != 0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}