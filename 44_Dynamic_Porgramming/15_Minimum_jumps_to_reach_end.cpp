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
        Given an array of integers where each element represents the max number of stepsthat can be made
        forward from that element.

        WAP to return the minimum no of steps to reach the end of the array (starting from the first element).
        If an element is 0,they cannot move through that element.
*/
/*
    Sample Test Case:
        Array = [1,3,5,8,9,2,6,7,6,8,9]

        Output:
            3
        
        Explanation:
            1->3->8->9
*/
/*
    DP states:
        1.  jumps[i] indicates the minimum niumber of jumps needed to reach arr[i] from arr[0]
        2.  we start from i = 0, and we have to find jumps[n-1]
        3.  For Calculating jumps[i],we run a nested loop 'j' from 0 to i-1
*/
/*
    Psuedo Code:
    jumps[0] = 0;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(i <= j + arr[j]){
                jumps[i] = min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
*/
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> jumps(n,INT_MAX);
    jumps[0] = 0;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(i <= j + arr[j]){
                jumps[i] = min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    cout<<jumps[n-1]<<endl;
    return 0;
}