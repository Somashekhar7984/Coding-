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
        You are given an array,A, of n elements.
        You have to remove exactly n/2 elements from array A and add it to another array B(intially empty).

        Find the maximum and minimum values of differences between these two arrays.

        We define the difference between these two arrays as :
        sigma(abs(A[i] - B[i]))

        Example:    
            Input:                      For maximum difference:
                4                           A : -3 0
                12 -3 10 0                  B : 12 10

            Output:                     For minimum difference:
                5 25                        A : -3 12
                                            B : 0 10

      Idea:
        To Maximise abs(A[i] - A[j])
            1.  A[i] should be as large as possible
            2.  A[j] should be as small as possible

        For a Sorted array,
            Maximum diff = (A[n-1] - A[0]) + (A[n-2] - A[1]) ... + (A[n/2] - A[n/2 - 1])
                         = (A[n-1] + A[n-2] + A[n-3] ... + A[n/2]) - (A[0] + A[1] + A[2] .... + A[n/2 - 1])

        To minimise abs(A[i] - A[j])
            1.  The difference should between A[i] and A[j] should be similar

        For a Sorted array,
        Minimum Diff = (A[1] - A[0]) + (A[3] - A[2]) .... + (A[n-1] - A[n-2])
                     = (Sum of odd elements) - (Sum of even elements)                                                           
*/
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long max = 0;
    long long min = 0;
    for(int i = 0;i<n/2;i++){
        max = max + (v[i+n/2] - v[i]);
        min = min + (v[2*i+1] - v[2*i]);
    }
    cout<<max<<" "<<min<<endl;
    return 0;
}