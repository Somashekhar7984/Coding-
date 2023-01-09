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
    Diophantine Equations
        These are the polynomial equations for which integral solution exists
        example : 3x + 7y = 1 or x^2 - y^2 = z^3

        Linear Diophantine Equation ---> ax + by = c
            Note : a,b,c belongs to I

        Solutions to these equations exist only if gcd(a,b) divides c

    Extended Eucild Algorithm:
        GCD(a,b) has property that
                ax + by = gcd(a,b)

            Now, we have to find the values of x and y.        

*/
const int N = 1e5+2,MOD = 1e9+7;
//  ax + by = gcd(a,b)

struct triplet{
    int x;
    int y;
    int gcd;
};
triplet extended_Euclid(int a,int b){
    if(b == 0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extended_Euclid(b,a%b);
    
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;;

    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    triplet ans = extended_Euclid(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    return 0;
}