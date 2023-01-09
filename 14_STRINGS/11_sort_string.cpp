#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    string s1 = "657293";
    sort(s1.begin(),s1.end());  // sotrs as per alphabetical order and CAPITAL letters are given in first
    cout<<s1<<endl;
    return 0;
}