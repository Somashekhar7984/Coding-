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
    Optimised Solution:
        1.  Compute Prefix Sum
            arr[] = {1,-1,1,-1};
            Prefix_sum[0] = arr[0]                              ====> 1
            Prefix_sum[1] = arr[0] + arr[1]                     ====> 0
            Prefix_sum[2] = arr[0] + arr[1] + arr[2]            ====> 1
            Prefix_sum[3] = arr[0] + arr[1] + arr[2] + arr[3]   ====> 0

    Now, we have to 
    1.  Map Prefix sum to a map
    2.  For every key,choose 2 values from the all occurences of particular prefsum(mC2)
    3.  Special Case : for prefsum 0,we have to also inculde them
*/
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }
    map<int,int> mp;        // For Count 
    if(mp.empty()){
        cout<<" The map is empty "<<endl;
    }
    int prefix_sum = 0;
    for(int i = 0;i<n;i++){
        prefix_sum = prefix_sum + V[i];
        mp[prefix_sum]++;
    }
    int ans = 0;
    map<int,int> :: iterator it;
    for(it = mp.begin();it != mp.end();it++){
        int c = it->second;
        ans = ans + ((c*(c-1))/2);
        if(it->first == 0){
            ans = ans + it->second;
        }
    }
    cout<<"The no of subarrays of (sum == 0) : "<<ans<<endl;
    return 0;
}