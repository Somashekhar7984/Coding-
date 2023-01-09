#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

string move_x(string str){
    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    string ans = move_x(str.substr(1));
    if(ch == 'x'){
        return ans+ch;
    }
    else{
        return ch+ans;
    }
}

int main(){
    string str = "axxbdxcefxhix";
    string newstr = move_x(str);
    cout<<newstr<<endl;
    return 0;
}