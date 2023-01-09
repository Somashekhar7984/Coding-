#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
// **************** Inclusion and Exclusion Principle *******************
/*
    how many numbers between 1 and 1000 are divisible by 5 or 7 ?

    ans = (divisible by 5) + (divisible by 7) - (divisible by 5 and 7)


*/
int divisible(int n,int a,int b){
    int c1 = n/a;   // No of numbers that are divisble by a 
    int c2 = n/b;   // No of numbers that are divisible by b
    int c3 = n/(a*b);// No of numbers that are divisible by both 'a' and 'b'
    return c1 + c2 - c3;
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<divisible(n,a,b)<<endl;
    return 0;
}