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
using namespace std;
/*
    Hashing-count frequency of elements in a given array

    for example:    
        arr[] = {2,2,2,1,1,4,3,4}

                key(elements)           value(Frequency)
                    2                       3
                    1                       2
                    4                       2
                    3                       1
*/
int main(){
    // map<key,value> mp;
    unordered_map<int,int> mp;
    int arr[] = {2,2,2,1,1,4,3,4};
    for(int i = 0;i<8;i++){
        mp[arr[i]]++;
    }
    unordered_map<int,int> :: iterator it;
    for(it = mp.begin();it != mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}