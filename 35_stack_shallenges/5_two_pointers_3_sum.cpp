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
    Input:
        n = 6
        target = 24
        12 3 7 1 6 9
    output:
        True (12,3,9)
*/
int main(){
    vector<int> v = {12,3,7,1,6,9};
    int target = 24;
    int n = 6;
    sort(v.begin(),v.end());
    for(int i = 0;i<n;i++){
        int start = i;
        int end = n-1;
        while(start < end){
            if(v[start] + v[end] == (target - v[i])){
                cout<<v[start]<<" "<<v[end]<<" "<<v[i];
                return 0;
            }
            else if(v[start] + v[end] < (target - v[i])){
                start++;
            }
            else{
                end--;
            }
        }
    }
    return 0;
}