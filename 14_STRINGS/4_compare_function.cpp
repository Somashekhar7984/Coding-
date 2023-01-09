#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    string s1 = "abc";
    string s2 = "xyz";

    if(s2.compare(s1) == 0){
        cout<<"Strings are Equal"<<endl;
    }
    else if(s2.compare(s1) > 0){
        cout<<"Strings are not equal"<<endl;
        cout<<"string s1 is less as per lexical order than s2"<<endl;
        cout<<s2.compare(s1)<<endl;
    }
    else{
        cout<<"Strings are not equal"<<endl;
        cout<<"string s2 is less as per lexical order than s1"<<endl;
        cout<<s1.compare(s2)<<endl;
    }

    return 0;
}