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
    Trapping Rain Water Harvesting

    Given non-negative integers representing an elevation map where the width of each bar is 1,
    Compute how much water it can trap after raining.

    Input:
        array : {0,1,0,2,1,0,1,3,2,1,2,1}
    Output:     The amount of water that has been stored 
        6

    Brute Force - DRY run:
        Height      0 1 0 2 1 0 1 3 2 1 2 1
        R           3 3 3 3 3 3 3 3 2 2 2 -     (maximum element on the right side of the position)
        L           - 0 1 2 2 2 2 3 3 3 3 3     (maximum element on the left side of the position)
        min(R,L)    0 0 1 2 2 2 2 3 2 2 2 0

        ans = {0,0,1,0,1,2,1,0,0,1,0,0}

        adding max(min(L,R)-height[i],0) to an answer

    
*/
int rain_water(vector<int> v){
    int ans = 0;
    int n = v.size();
    stack<int> st;      // stack stores the indices of the elements
    for(int i = 0;i<n;i++){
        while(!st.empty() && v[st.top()] < v[i]){
            int curr = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            else{
                int len = i - st.top() - 1;
                int height = (min(v[st.top()] , v[i]) - v[curr]);
                ans = ans + height*len;
            }
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int> V =  {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(V)<<endl;
    return 0;
}