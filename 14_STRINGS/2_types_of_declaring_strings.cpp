#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string str;
    string str1(5,'n');
    cout<<str1<<endl;

    string str2 = "Apnikaksha";
    cout<<str2<<endl;

    string str3;
    getline(cin,str3);  // To get space including in the string
    cout<<str3<<endl;
    return 0;
}