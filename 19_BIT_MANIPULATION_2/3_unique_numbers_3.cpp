#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// ********* Now here array contains thirce expect one element *********
//              we need to find the element
/*
    {   1,   3,     2,     3,     4,      2,    1,      1,    3,    2   }
    (0001) (0011) (0010) (0011) (0100) (0010) (0001) (0001) (0011) (0010)
                here 1,2,3 occurs 3 times while 4 comes only once 
*/
bool getBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
int setBit(int n,int pos){
    return (n | (1<<pos));
}
int unique(int arr[],int n){
    int result = 0;
    for(int i = 0;i<64;i++){
        int sum = 0;
        for(int j = 0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3 != 0){
            result = setBit(result,i);
        }
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int res = unique(arr,n);
    cout<<res<<endl;
    return 0;
}