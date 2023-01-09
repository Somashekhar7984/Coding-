#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;


int main(){
    string str;
    cin>>str;
    for(int i = 0;i<str.length();i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    cout<<str<<endl;
    for(int i = 0;i<str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    cout<<str<<endl;
    return 0;
}