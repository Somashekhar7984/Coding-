#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//          NUMBER FORMED FROM SUB ARRAY OF K , DIVISIBLE BY 3
/*
    For a given array and an integer K,check if any subarray of size K exists in the array such that elements in 
    the sub array form a number divisible by 3.
        Appoarch 1:
            Compute the numbers formed by all possible subarrays of size K.
            Check for divisible by 3

            Time Complexity = O(n^2);
        
        Appoarch 2:
            Fact : A number is divisible by 3 if and only if the sum of its digits is divisible by 3

        1.  sum of initial K elements from the array
        2.  Use sliding window techinque and one by one, start subtracting elements from the end & adding from the end
        3.  At each step, check if sum is divisible by 3 or not. if it is, print the elements

            Time Complexity = O(n)     
 */
void compute_number_from_subarray(vector<int> arr,int K){
    pair<int,int> ans;
    int sum = 0;

    for(int i = 0;i<K;i++){
        sum = sum + arr[i];
    }

    bool found = false;
    if(sum%3 == 0){
        ans = make_pair(0,K-1);
        found = true;
    }

    for(int i = K;i<arr.size();i++){
        if(found){
            break;
        }
        sum = sum + arr[i] - arr[i-K];
        if(sum%3 == 0){
            ans = make_pair(i-K+1,i);
            found = true;
        }
    }
    if(!found){
        ans = make_pair(-1,0);
    }
    if(ans.first == -1){
        cout<<"No such subarray exists "<<endl;
    }
    else{
        for(int i = ans.first;i<=ans.second;i++){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    vector<int> arr = {23,45,12,56,82};
    int K = 3;
    compute_number_from_subarray(arr,K);
    return 0;
}