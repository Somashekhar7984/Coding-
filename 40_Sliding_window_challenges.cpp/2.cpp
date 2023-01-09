#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//              Smallest Sub array with sum > X
/*
    Problem:
        For a given array and an integer X,
        find the minimum subarray size for which sum > X

    Approach 1:
        Compute Sum of All subarrays & check the Condition
        Time Complexity = O(n^2)

    Approach 2;
        Sliding Window
            1.  Use Variables ans , sum & start
            2.  Iterate over array & start adding elements to sum
            3.  if sum > X, remove elements from the start

                Time Complexity = O(n);


*/
int smallest_subarray_with_sum(int arr[],int n,int X){
    int sum = 0;
    int min_length = n + 1; // Final answer
    int start = 0;
    int end = 0;
    while(end < n){
        while(sum <= X && end < n){
            sum = sum + arr[end];
            end++;
        }


        while(sum > X && start < n){
            if(end - start < min_length){
                min_length = end - start; 
            }
            sum = sum - arr[start];
            start++;
        }
    }

    return min_length;
}
int main(){
    int arr[] = {1,4,45,6,10,19};
    int X = 51;
    int n = 6;
    int min_length = smallest_subarray_with_sum(arr,n,X);
    if(min_length == n+1){
        cout<<"No Such sub array exists "<<endl;
        return 0;
    }
    cout<<"The minimum size of subarray with sum (< X) : "<<min_length<<endl;
    return 0;
}