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
    Given a set of coins and a value of 'V'. Find the number of ways we can make change of V.
        eg: set = S = {1,2,3} V = 3;
                Ways = {3},{1,2},{1,1,1}

    To Make ways with ecery Coin, we have 2 Options
        a. Take it.
        b. Do not take it

        Count(S[],m,V) = count(S[],m,V-Sm) + count(S[],m-1,V);

            Since it can be represented as a recurrence as a recurrence relation. Hence it has Optimal Substructure Property
            
*/
int main(){
    
    return 0;
}