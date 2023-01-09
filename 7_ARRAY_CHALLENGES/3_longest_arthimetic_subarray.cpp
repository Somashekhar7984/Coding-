#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
// Google Kickstart Problem
// arithmetic array
/*
        An arthimetic array in an array that contains at least two integers and the differences between 
    consecutive integers are equal.
    For Example : [9,10] , [3,3,3] , [9,7,5,3]  are arthimetic arrays
    while [1,3,3,7] , [2,1,2] , [1,2,4] are not arthimetic arrays

    saravati has an array of N non-negative Integers .the i-th integer of the array is Ai.she wants to choose a
    contiguous arthimetic sub-array from her array that has the maximum length. Please help her to determine 
    the length of the longest contiguous arthimetic subarray
*/

/*
INPUT : the first line of the input gives the number of test cases, T. T test cases follow.Each test case begins
        with a line containing the integer N.The second line contains N integers.The i-th integer is Ai.
OUTPUT : for each case , output one line containing case #x : y, where x is the test case number (starting from 1)
         and y is the length of the longest contiguous arthimetic subarray.        
*/


// Work on the sub-array part


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 2;
    int pd = arr[1] - arr[0];
    int j = 2;
    int current_length = 2;
    int i = 2;
    int new_array[n];
    new_array[0] = arr[0];
    new_array[1] = arr[1];
    while(j<n){
        if(pd == arr[j] - arr[j-1]){
            current_length ++;
            new_array[i] = arr[j];
            i++;
        }
        else{
            pd = arr[j] - arr[j-1];
            current_length = 2;
        }
        ans = max(ans,current_length);
        if(ans != current_length){
            new_array[0] = arr[j-1];
            new_array[1] = arr[j];
            i = 2;
        }
        j++;
    }
    cout<<ans<<endl;
    for(int i = 0;i<ans;i++){
        cout<<new_array[i]<<" ";
    }
    return 0;
}