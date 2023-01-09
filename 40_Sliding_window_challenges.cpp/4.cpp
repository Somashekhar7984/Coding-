#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//              Subarray of size K with palindromic concatenation
/*
    for a given array and an integer K,
    check if any subarray of size K exists in the array such that concatenation of elements form a palindrome.

    Approach 1:
        Generate all subarrays of size K
            Time Complexity - O(n^2)
        check if their concatenation forms a palindrome
            Time Complexity - O(n)
                Total Complexity == O(n^3)

    Approach 2:
        1.  Store Concatenation of initial K elements
        2.  Iterate over the array & start deleting elements from the start and adding elements from the end
        3.  At each step , check if concatanation is a palindrome.
            Time Complexity = O(n^2)                
*/
bool isPalindrome(int n){
    int temp = n;
    int num = 0;
    while(temp > 0){
        num = num*10 + (temp%10);
        temp = temp/10;
    }
    if(num == n){
        return true;
    }
    return false;
}
int find_palindromic_sub_array(vector<int> arr,int k){
    int num = 0;

    for(int i = 0;i<k;i++){
        num = num*10 + arr[i];
    }

    if(isPalindrome(num)){
        return 0;
    }
    
    for(int j = k;j<arr.size();j++){
        num = (num % (int)pow(10,k-1))*10 + arr[j];

        if(isPalindrome(num)){
            return j-k+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,3,5,1,1,5};
    int k = 4;
    int ans = find_palindromic_sub_array(arr,k);
    if(ans == -1){
        cout<<"Palindromic subarray doesn't exist"<<endl;
    }
    else{
        for(int i = ans;i<ans+k;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}