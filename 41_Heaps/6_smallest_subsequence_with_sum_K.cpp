#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
    Given an array  ==> 1 1 3 2 8  && k = 13;

        subarray    :    Continuous Block of elements
        subsequence :    Not Necessarily Continuous ,but order should remain as in original array
    "Every Subarray is subsequence but not vice-versa"
    Appoarch :
        1.  Keep a max heap and insert all the elements
        2.  Keep opping the elements and keep adding them to a variable sum and maintain count;
        2.  When sum>=k , then Quote the answer(count)
*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> V(n);
    for(int i = 0;i<n;i++){
        cin>>V[i];
    }
    priority_queue<int,vector<int>> pq;

    for(int i = 0;i<n;i++){
        pq.push(V[i]);
    }

    int sum = 0;
    int count = 0;
    while(!pq.empty()){
        sum = sum + pq.top();
        pq.pop();
        count++;
        if(sum >= k){
            break;
        }
    }
    if(sum < k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<count<<endl;
    }
    return 0;
}