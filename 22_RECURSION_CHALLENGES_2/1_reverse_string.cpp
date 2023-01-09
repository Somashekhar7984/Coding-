#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*

my own code 

void reverse(string str,int i){
    if(i == str.length()){
        return;
    }
    reverse(str,i+1);
    cout<<str[i];
}
*/
void reverse(string str){
    if(str.length() == 0){
        return;
    }

    string rest_of_str = str.substr(1);  // This function here gives the substring starting from index 1 the string
    reverse(rest_of_str);
    cout<<str[0];
}
int main(){
    string str;
    cin>>str;
    //reverse(str,0);
    reverse(str);
    return 0;
}