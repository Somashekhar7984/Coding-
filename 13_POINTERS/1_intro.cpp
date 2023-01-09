#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
 //         *******  INTRODUCTION  ******
 /*
        Pointers are variables that store the address of other variables 
 */
  
int main(){
    int a = 10;
    int *aptr;
    aptr = &a;  // & gives the address of the element

    cout<<aptr<<endl; // gives the address of the 'a'
    cout<<&a<<endl; // gives the address of the 'a'
    cout<<a<<endl;
    cout<<*aptr<<endl; // gives the value of a

    *aptr = 20; // Now updating the 'a' with the pointer

    cout<<a<<endl;

    return 0;
}