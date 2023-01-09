#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string str = "nincompoop";
    string s = str.substr(2,5); // starting index and no of characters required for the string
    cout<<s<<endl;
    return 0;
}