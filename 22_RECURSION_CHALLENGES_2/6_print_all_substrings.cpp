#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

// void print_all_substrings(string str){
//     if(str.length() == 0){
//         return;
//     }
//     for(int i = 1;i<=str.length();i++){
//         cout<<str.substr(0,i)<<endl;
//     }
//     print_all_substrings(str.substr(1));
// }

void subseq(string str,string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string rest_of_string = str.substr(1);
    subseq(rest_of_string,ans);
    subseq(rest_of_string,ans+ch);
}

int main(){
    string str;
    cin>>str;
    //print_all_substrings(str);
    subseq(str,"");
    return 0;
}