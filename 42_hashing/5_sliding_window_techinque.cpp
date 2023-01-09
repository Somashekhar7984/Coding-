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
    Optimal Solution:
        1.  Compute sum of the first K elements(i = 0 to i = k)
        2.  while increasing i, subtract a[i-1] and add a[i + k - 1] in the previous sum,which will become current sum
*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }
    int sum = 0;
    for(int i = 0;i<k;i++){
        sum = sum + V[i];
    }
    int min = sum;
    for(int i = k;i<n;i++){
        sum = sum + V[i] - V[i-k];
        if(sum < min){
            min = sum;
        }
    }
    cout<<"The minimum sum of subarray of size k : "<<min<<endl;
    return 0;
}