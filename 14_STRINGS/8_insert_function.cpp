#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string s1 = "nincompoop";
    s1.insert(2,"lol"); // This inserts the given string to it from the index 
    cout<<s1<<endl;
    cout<<s1.size()<<endl; // This gives the size of the string (no of characters in the string)
    return 0;
}