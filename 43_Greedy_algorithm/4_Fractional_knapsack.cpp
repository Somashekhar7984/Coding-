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
    Problem:
        We are given 'n' items with {weight,value} of each itm and the capacity of knapsack(sack) 'W'.
        We nedd to put these items in knapsack such that final value of items in knapsack is maximum.

     Eg:
        Value(for the total given weight)   :     21      24      12      40      30
        Weight                              :      7      4        6       5       6

                W(Weight that can be hold by sack) = 20kg
        Now find Value per unit weight
        (Value/unit)                        :      3      6        2       8       5

        Now Sort the (Value/weight) in decresing Order

            Pick from the starting till our knapsack has capacity

            Then the maximum value for the given example is = 40 + 24 + 30 + 15 = 109 
*/
bool Compare(pair<int,int> p1,pair<int,int> p2){
    double v1 = (double)(p1.first/p1.second);   
    double v2 = (double)(p2.first/p2.second);
    // v1,v2 are value per unit weight 
    return (v1 > v2);
    // returning in such way that value per unit is in decreasing order
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> V(n);
    for(int i=0;i<n;i++){
        cin>>V[i].first>>V[i].second;
    }
    int w;
    cin>>w;
    sort(V.begin(),V.end(), Compare);
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(w > V[i].second){        // second == weight
            ans = ans + V[i].first; // first == value
            w = w - V[i].second;
            continue;
        }
        double vw = (double)V[i].first/V[i].second;
        ans = ans + (vw*w);
        w = 0;
        break;
    }
    cout<<"The maximum value of loot that robber can get is : "<<ans<<endl;
    return 0;
}