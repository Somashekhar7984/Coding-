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
    Binary Exponentiation
        Many times , our answer is out of range of int.To avoid this we use modulo operation to overcome this 
        problem.Some of the properties of modulo operation are:
                (a+b)%m = (a%m) + (b%m);
                (a*b)%m = (a%m)*(b%m);
                (a-b)%m = (a%m) - (b%m);
                (a/b)%m = (a%m)*((b^-1)%m);   here b^-1 ==> Multiplicative MOD inverse of the B with m

    Recursive version:
        a^n
            Cases : First Case n --> odd
                        a^n = a^(n/2) * a^(n/2) * a
                    Second Case n --> EVEN
                        a^n = a^(n/2) * a^(n/2)
*/
const int N = 1e5+2 , MOD = 1e9+7;

int power(int a,int n){
    
    a = a%MOD;
    int ans = 1;
    while(n>0){
        if(n&1){        // --> If n is ODD
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        n = n>>1;       // n is divided by 2
    }
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<power(a,n)<<endl;
    return 0;
}