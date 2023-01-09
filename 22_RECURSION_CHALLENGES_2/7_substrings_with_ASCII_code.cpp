#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

void subseq(string str,string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }

    char ch = str[0];
    int code = ch;
    string rest_of_string = str.substr(1);

    subseq(rest_of_string,ans);
    subseq(rest_of_string,ans+ch);
    subseq(rest_of_string, ans + to_string(code));
}


int main(){
    string str;
    cin>>str;
    subseq(str,"");
    return 0;
}