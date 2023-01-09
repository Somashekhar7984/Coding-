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
    Consider the equation
        (A*B)%m = 1;
            Then  B is said to be multiplicative modulo inverse of A with m

            Examples        Answers
            (17xB)%3 = 1        2
            (14xB)%5 = 1        4
            (12xB)%7 = 1        3
            (19xB)%2 = 1        1
        Note: Multiplicative Modulo inverse exists only if A and B are CO-prime 
            i.e.    gcd(A,m) = 1

*/
const int N = 1e5+2,MOD = 1e9+7;
struct triplet{
    int x,y,gcd;
};
triplet extended_euclid(int a,int b){
    if(b == 0){
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extended_euclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;

    return ans;
}
int multiplicative_modulo_inverse(int a,int m){
    triplet ans = extended_euclid(a,m);
    return ans.x;
}
int main(){
    int a,m;
    cin>>a>>m;
    int ans = multiplicative_modulo_inverse(a,m);
    if(ans < 0){
        ans = ans + m;
    }
    cout<<ans<<endl;
    return 0;
}