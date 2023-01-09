#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string s1 = "abc";
    cout<<s1<<endl;
    s1.clear();
    cout<<s1<<endl; // This deletes the data in the string
    if(s1.empty()){ // This function checks whether a string is empty or not
        cout<<"The string is empty"<<endl;
    }
    return 0;
}