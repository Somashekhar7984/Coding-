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
    Stock Span Problem:
        The Span of the stock's price today is defined as the maximum number of consecutive days
        (starting from today and going backwards) for which the today's price is greater than or equal the previous days

        Find the span of the stocks for all the days
*/
/*
    BRUTE FORCE:

        for(int i = 0;i<n;i++){
            int days = 0;
            for(int j = i;j>=0;j--){
                if(prices[i] >= prices[j]){
                    days++;
                }
                else{
                    break;      // whenever we find a previous day where the stock price is greater than the today's price
                }
            }
            ans.push_back(days);
        }
*/
int main(){
    
    int stock_prices[] = {100,80,60,70,60,75,85};
    stack<pair<int,int>> st;
    int n = sizeof(stock_prices)/sizeof(int);
    vector<int> ans;
    // In Pair ==> first is stock prices 
    //         ==> second is days
    for(int i = 0;i<n;i++){
        int days = 1;
        while(!st.empty() && st.top().first <= stock_prices[i]){
            days = days + st.top().second;
            st.pop();
        }
        st.push({stock_prices[i],days});
        ans.push_back(days);
    }
    for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}