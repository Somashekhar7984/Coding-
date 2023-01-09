#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// **** Same as previous problem ****
/*
    but here now we have two unique numbers
            {   2,     4,     6,      7,     4,     5,     6,    2   }
              (0010) (0100) (0110) (0111) (0100) (0101) (0110) (0010)
    here two unique numbers are 7 , 5
    if we take a xor of all elements then the result will be  = 7^5 = (0111)^(0101) == (0010)

*/
int setBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}
void unique(int arr[],int n){
    int xorsum = 0;
    for(int i = 0;i<n;i++){
        xorsum = (xorsum^arr[i]);
    }
    int temp = xorsum;
    // Now we should find the right most setbit(1) in the binary form
    int setbit = 0;
    int pos = 0;
    while(setbit != 1){
        setbit = (xorsum&1);
        pos++;   // we will get the position of the setbit position in the xorsum 
        xorsum = (xorsum>>1);
    }
    int newxor = 0;
    for(int i = 0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor = (newxor^arr[i]); // This newxor is one of the given two unique numbers in the array
        }
    }
    cout<<newxor<<endl;
    cout<<(newxor^temp)<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    unique(arr,n);

    return 0;
}