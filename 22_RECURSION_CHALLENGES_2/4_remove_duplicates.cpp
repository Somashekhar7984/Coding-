#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

// This code will remove duplicates when the string is in sorted order
string remove_duplicates(string str){
    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    string ans = remove_duplicates(str.substr(1));
    if(ch == ans[0]){
        return ans;
    }
    return ch + ans;

}

int main(){
    string str = "aaaabbbbeeecddddd";
    string newstr = remove_duplicates(str);
    cout<<newstr<<endl;
    return 0;
}