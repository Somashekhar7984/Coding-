#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

void permutation_of_string(string str,string ans){

    if(str.length() == 0){
        cout<<ans<<endl;
    }
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        permutation_of_string(ros,ans+ch);
    }

}

int main(){
    string str;
    cin>>str;
    permutation_of_string(str,"");

    return 0;
}