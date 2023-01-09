#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
        0   1   2   3
        0 --------->3
        0-->1------>3
        0------>2-->3
        0-->1-->2-->3

*/

int countPath(int start,int end){
    if(start == end){
        return 1;
    }
    if(start > end){
        return 0;
    }
    int count = 0;
    for(int i = 1;i<=6;i++){
        count = count + countPath(start+i,end);
    }
    return count;
}

int main(){
    int start = 0;
    int end = 3;
    int count = countPath(start,end);
    cout<<count<<endl;
    return 0;
}