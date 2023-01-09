#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    phone digit 1 --> "./"
    phone digit 2 --> "abc"
    phone digit 3 --> "def"
    phone digit 4 --> "ghi"
    phone digit 5 --> "jkl"
    phone digit 6 --> "mno"
    phone digit 7 --> "pqrs"
    phone digit 8 --> "tuv"
    phone digit 9 --> "wxyz"

    we will be given some number like 1,2
       we are supposed to write all possbile words that can be formed with the letters of the numbers they contain
*/
/********************* KEYPAD *************************/

string keypadArr[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string str,string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string code = keypadArr[ch-'0'];
    string ros = str.substr(1);
    for(int i = 0;i<code.length();i++){
        keypad(ros , ans + code[i]);
    }


}

int main(){
    keypad("234","");

    return 0;
}