#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int countPathMaze(int n,int i,int j){
    if(i == n-1 && j == n-1){
        return 1;           // This is for the base case reaching the end (n-1,n-1)
    }
    if(i>=n || j>=n){
        return 0;
    }
    
    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);
}

int main(){
    cout<<countPathMaze(3,0,0);  // starting point (0,0)
    return 0;
}