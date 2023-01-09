#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
                    LARGEST RECTANGLE IN HISTOGRAM
    Given an array. Each element represents the height of the histogram's bar and the width of each bar is 1.
    Find the area of the largest rectangle in the histogram

    Input : Array = [ 2, 1, 5, 6, 2, 3 ]

    Histogram will be like:
              
                     _              
                 _   _
                 _   _
                 _   _       _
        _        _   _   _   _
        _    _   _   _   _   _
        _    _   _   _   _   _ 
    The maximum rectangle that can fit in the above histogram is = 10

        consider 5, 6 ==> This ends up in getting the largest rectangle with height = 5 and width = 2

    Brute Force:    O(n^2)
    int ans = 0;
    int n = arr.size();
    for(int i = 0 ;i<n;i++){
        int min_height = INT_MAX;
        for(int j = i+1;j<n;j++){
            min_height = min(arr[j],min_height);
            int len = j-i+1;
            ans = max(ans,len*min_height);
        }
    }
    cout<<ans<<endl;


    Stack Approach:
        Potential Area and Pop till stack elements is greater
*/
int get_max_area(vector<int> v){
    int n = v.size();
    int ans = 0;
    int i = 0;
    v.push_back(0);
    stack<int> st;  // Store the indices of the elements in the arr
    while(i < n){
        while(!st.empty() && v[st.top()] > v[i]){
            int height = v[st.top()];
            st.pop();
            if(st.empty()){
                ans = max(ans,height*i);
            }
            else{
                int len = i - st.top() - 1;
                ans = max(ans,height*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){
    vector<int> v = {2,1,5,6,2,3};
    cout<<get_max_area(v)<<endl;
    return 0;
}
