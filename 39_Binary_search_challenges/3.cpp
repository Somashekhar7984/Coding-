#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//              PAINTER'S PARTITION PROBLEM
/*
    n - length of n different boards
    m - painters available

    A Painters paints 1 unit of board in 1 unit of time & each Painter will paint Consecutive boards.
    Find the minimum time that will be required to paint all the boards.

    Boards = [10,20,30,40]  (n = 4)
    painters(m) = 2

    Possible Partitions 
    [10],[20,30,40] ==> 10,90 ==> Max = 90
    [10,20],[30,40] ==> 30,70 ==> Max = 70
    [10,20,30],[40] ==> 60,40 ==> Max = 60

    Apply binary search for minimum & maximum possible values of 'min' length of boards to be painted.
    Check the feasibility of this chosen value.

    Feasibility:
        Assign boards to each painter in a sequential manner, while the current length of assigned boards don't
        exceed the value set by binary search.

        if during allocation the number of painters don't exceed the limit of 'm',
        then the solution is feasible.
        else, it isn't
*/
int find_feasible(int boards[],int n,int Upper_limit){
    int sum = 0;
    int painters = 1;
    for(int i = 0;i<n;i++){
        sum = sum +boards[i];
        if(sum > Upper_limit){
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}
int painters_partition(int boards[],int n,int m){
    int total_length = 0;   // Total length of all the boards
    int k = 0;  // The max length out of all boards
    for(int i = 0;i<n;i++){
        k = max(k,boards[i]);
        total_length = total_length + boards[i];
    } 
    int low = k;
    int high = total_length;
    while(low < high){
        int mid = (low + high)/2;
        int painters = find_feasible(boards,n,mid);
        if(painters <= m){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main(){
    int boards[] = {10,20,30,40};
    int n = 4;
    int m = 2;
    cout<<"The minimum time is : "<<painters_partition(boards,n,m)<<endl;
    return 0;
}