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
            TOP K MOST ELEMENTS ELEMENT IN THE STREAM

    Given an array : 1 2 2 2 3 4        and k = 2
        we have to output elemnts in decresing frequency till we reach (k+1)th distinct elements
    
    Approach (Hashing)
    1.  Create a map
    2.  while travelling, Keep track of elemnts and when we find (k+1)th without element = break;
    3.  Output the element and frequency using map
*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }

    map<int,int> mp;
    for(int i = 0;i<n;i++){
        int present_size = mp.size();
        if(mp[V[i]] == 0 && present_size == k){
            break;
        }
        mp[V[i]]++;
    }
    
    vector<pair<int,int>> ans;
    map<int,int> :: iterator it;
    for(it = mp.begin(); it != mp.end();it++){
        if(it->second != 0){
            ans.push_back({it->second,it->first});
        }
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    vector<pair<int,int>> :: iterator it1;
    for(it1 = ans.begin();it1 != ans.end();it1++){
        cout<<it1->second<<" "<<it1->first<<endl;
    }
    return 0;
}