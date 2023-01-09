#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string str = "786";
    int x = stoi(str); // string to integer
    cout<<x<<endl;

    x = 123;
    cout<<to_string(x)<<endl; // integer to string
    return 0;
}