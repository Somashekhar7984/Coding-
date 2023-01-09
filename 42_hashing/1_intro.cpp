#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
/*
    HASHING - STL 
            Two Data structures are used:
                    ==> Maps                ==> Unordered Maps
    insertion = O(log N)                    Insertion = O(1)
    Accessing = O(log N)                    Accessing = O(1)
    Deletion = O(log N)                     Deletion = O(n)
    Implemented Using = RED-BLACK tree      Hash tables (Basically array og buckets)
        
            key,value                               key,value
        map<int,int> mp;                    unordered_map<int,int> ump;
*/
int main(){
    map<int,int> m;
    m[8] = 2;   // for key = 8 --> value = 2
    

    return 0;
}