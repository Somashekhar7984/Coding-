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
        Kadane Algorithm : Maximum subarray sum

        Problem:   you are given an array. Your task is to find the maximum sum of subarray which can be found using the above array

                Eg : -5 -1 5 -3 -1 2 3 -6
            
        Approach :
            1.  Maintain Two Variables Curr and Max Till Now
                    Initialise , curr = 0
                                Max , till now = 0;
            2.  Iterate i = 0 to i = n-1 and do
                        curr = curr + a[i]
                        Max Till Now = max[max till now,curr]
            3.  if curr < 0 then 
                    do curr = 0 {Basically neglecting the elements contributing to negative sum}
            4.  When Loop ends, output max till now        
*/
int kadane_algorithm(vector<int> V,int n){
    int curr = 0;
    int maxi = 0;
    for(int i = 0;i<n;i++){
        curr = curr + V[i];
        maxi = max(maxi,curr);
        if(curr < 0){
            curr = 0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    for(int i =0 ;i<n;i++){
        cin>>V[i];
    }
    int result = kadane_algorithm(V,n);
    cout<<result<<endl;
    return 0;
}