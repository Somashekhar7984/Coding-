#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//      Perfect Numbers in Subarrays 
/*
    For a given array and an integer K,
    find the maximum perfect numbers in a subarray of size K.

    Perfect number : a number if it is equal to the sum of its proper divisors(positive divisors) except for the number
                        itself.
                    eg: number = 6, Proper Divisors = [1,2,3]

        Approach 1:
            Generate all subarrays of size K & count number of perfect numbers
            Time Complexity = O(n*K)

        Approach 2:
                Trick:  
                    Convert the given array into a binary array with values 0 & 1 only.
                    Traverse the array & if the number at index i is perfect number then replace value at ith index 
                    with '1'
                    else with a '0'

                Sliding Window:
                1.  Initialize a variable to store sum of divisors.
                2.  Traverse every number less than arr[i] and add it to sum if it is a divisor of arr[i]
                3.  if the sum of all divisors is equal to arr[i], then only the number is a perfect number.

                    Find the maximum sum of subarray from all possible subarrays of size K

                        Time Complexity = O(n*sqrt(n))

        eg : arr[] = {1,2,3,6}
                k = 2;

                required sub array = {3,6}                               
*/ 
int max_sum(int arr[],int n,int k){
    if(n<k){
        cout<<"Invaild Values"<<endl;
        return -1;
    }
    int res = 0;
    for(int i = 0;i<k;i++){
        res = res + arr[i];
    }
    int sum = res;
    for(int j = k;j<n;j++){
        sum = sum + arr[j] - arr[j-k];
        res = max(res,sum);
    }
    return res;
}
bool is_number_perfect(int n){
    int sum = 1;
    for(int i = 2;i<sqrt(n);i++){
        if(n%i == 0){
            if(i == n/i){
                sum = sum + i;
            }
            else{
                sum = sum +i + (n/i);
            }
        }
    }
    if(sum == n && n != 1){
        return true;
    }
    return false;

}
int max_number_of_perfect_number(int arr[],int n,int k){
    for(int i = 0;i<n;i++){
        if(is_number_perfect(arr[i])){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }
    return max_sum(arr,n,k);
}
int main(){
    int arr[] = {28,2,3,6,496,90,8128,24};
    int K = 4;
    int n = 8;
    cout<<max_number_of_perfect_number(arr,n,K)<<endl;
    return 0;
}