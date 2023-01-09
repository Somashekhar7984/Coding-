#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
//   ********************  NO OF one's in binary form ***************
/*
    n = 19 --> (01011)          n = 18 -->(01010)       n = 16 --> (010000)
    n-1 = 18 --> (01010)        n-1 = 17 -->(01001)     n-1 = 15 -->(001111)

    n = (n)&(n-1)               n = (n)&(n-1)           n = n&(n-1)
      = (01011)&(01010)           = (01010)&(01001)       = (010000)&(001111)
      = (01010) -> 18             = (01000) -->16         = (000000) --> 0  


*/
int main(){
    int n;
    cin>>n; // n is an integer
    int no_of_1s = 0;
    while(n!=0){
        n = n&(n-1);
        no_of_1s++;
    }
    cout<<no_of_1s<<endl;
    return 0;
}