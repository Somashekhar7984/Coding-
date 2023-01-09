#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// *********** Program to find the unique number in an array ***************
/*
   array = {2,4,6,3,4,6,2};

   A    B    A^B    ==> this helps us to remove the duplicate elements in the array(That occurs in the even no of times)    

   0    0     0         eg : 6 --> (0110)
   0    1     1              6 --> (0110)
   1    0     1                  ---------- 
   1    1     0                     (0000)
*/
int main(){
    int ans = 0;
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        ans = (ans ^ arr[i]);
    }
    cout<<ans<<endl;
    return 0;
}