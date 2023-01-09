#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*

    Given maze 
            {1,0,1,0,1}     all 1 can be used to used(there is a way through it)
            {1,1,1,1,1}     all 0's will block the way of the rat
            {0,1,0,1,0}
            {1,0,0,1,1}
            {1,1,1,0,1}

    now we need to find the route for the rat to escape for the maze
            {1,0,0,0,0}
            {1,1,1,1,0}
            {0,0,0,1,0}
            {0,0,0,1,1}
            {0,0,0,0,1}        
*/
/*
    (x,y) = the position of the rat in the maze
    n = size of matrix
*/
bool isSafe(int** arr,int x,int y,int n){
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}
bool rat_in_maze(int** arr,int x,int y,int n,int** solArr){
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        solArr[x][y] = 1;
        if(rat_in_maze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(rat_in_maze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y] = 0;   // BACKTRACKING
        return false;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i = 0;i<n;i++){
        arr[i] = new int[n];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int** solArr = new int*[n];
    for(int i = 0;i<n;i++){
        solArr[i] = new int[n];
        for(int j = 0;j<n;j++){
            solArr[i][j] = 0;
        }
    }
    cout<<endl;
    if(rat_in_maze(arr,0,0,n,solArr)){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No Route"<<endl;
    }
    return 0;
}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/