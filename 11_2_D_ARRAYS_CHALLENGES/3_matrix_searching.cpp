#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

// Problem Statement
/*
    Given a nxm matrix
    Write an algorithm to find that the given value exists in the matrix or not
    
    integers in each row are sorted in ascending from left to right
    integers in each column are sorted in ascending from top to bottom

    eg :   1 4 5 11
           2 5 8 12
           3 6 9 16
           10 13 14 17

*/


/*
IDEA 
  ==>  Start from top right corner (row == 0 , column == n-1)
  ==>  you at (r,c)
         if(matrix[r][c] == target){
             return true;
         }
         else if(matrix[r][c] > target){
             c--;
         }
         else{
             r++;
         }

*/
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    int r = 0;
    int c = n-1;
    while( r < n && c >= 0){
        if(arr[r][c] == target){
            cout<<"Element Found at : "<<endl;
            cout<<r+1<<" "<<c+1<<endl;
            return 0;
        }
        else if(arr[r][c] > target){
            c--;
        }
        else{
            r++;
        }
    }
    cout<<"Element Not Found"<<endl;
    return 0;
}



// int main(){
//     int n,key;
//     cin>>n;
//     int arr[n][n];
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     cin>>key;
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<n;j++){
//             if(key == arr[i][j]){
//                 cout<<"Element Found at : "<<endl;
//                 cout<<i+1<<" "<<j+1<<endl;
//                 return 0;
//             }
//         }
//     }
//     cout<<"Element NOT found";
//     return 0;
// }