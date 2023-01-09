#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int a = 10;
    int *aptr;
    aptr = &a;  // int *aptr = &a;
    cout<<aptr<<endl;

    aptr++;

    cout<<aptr<<endl;
    return 0;
}