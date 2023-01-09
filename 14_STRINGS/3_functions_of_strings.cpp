#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string str;

    string s1 = "fam";
    string s2 = "ily";
    
    // way 1
    // s1.append(s2);
    // cout<<s1<<endl;

    // way 2
     // cout<< s1 + s2 <<endl;

    // way 3
  /*  s1 = s1 + s2;
    cout<<s1<<endl;  */

    // Accessing the element in a string
    cout<<s1[1]<<endl;

    string abc = "whfiBZBCIUWEFQL";
    abc.clear();
    cout<<abc<<endl;
    return 0;
}