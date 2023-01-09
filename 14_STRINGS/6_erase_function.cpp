#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string s1 = "nincompoop";
    s1.erase(3, 3);// (starting index(0 based index) , no of elements to be removed from starting index)
    s1.erase(1,1);
    cout<<s1<<endl;
    return 0;
}