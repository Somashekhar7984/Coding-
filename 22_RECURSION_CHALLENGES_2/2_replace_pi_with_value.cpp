#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
void replace_pi(string str){
    if(str.length() == 0){  // Base case
        return;
    }
    if(str[0] == 'p' && str[1] == 'i'){
        cout<<3.14;
        replace_pi(str.substr(2));
    }
    else{
        cout<<str[0];
        replace_pi(str.substr(1));
    }
}
int main(){
    // string str = "soma";
    // str = "shekhar" + str;   ===> This gives output "shekharsoma"
    // cout<<str;
    string str;
    cin>>str;
    replace_pi(str);
    return 0;
}