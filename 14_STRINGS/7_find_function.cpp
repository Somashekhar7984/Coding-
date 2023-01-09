#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string s1 = "nincompoopcom";
    cout<<s1.find("com")<<endl; // this gives the index of first matching element
    cout<<s1.find("poo")<<endl;
   // cout<<s1.find("soma")<<endl;
   cout<<s1.find('p')<<endl;
    return 0;
}