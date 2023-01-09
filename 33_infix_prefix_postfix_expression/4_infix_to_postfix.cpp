#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
                    INFIX to POSTFIX
      
      ( a - b / c ) * ( a / k - l )  ===>  a b c / - a k / l - *

        if operand
            print
        if '('
            push to stack
        if ')'
            pop from the stack and print until '(' is found
        if operator
            pop from stack and print until an operator with less precedence is found      
*/
int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infix_to_postfix(string str){
    stack<char> st;
    string res = "";
    for(int i = 0;i<str.length();i++){
        if( (str[i] >= 'a' && str[i] <= 'z') || ( str[i] >= 'A' && str[i] <= 'Z') ){
            res = res + str[i];
        }
        else if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res = res + st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(str[i])){
                res = res + st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        res = res + st.top();
        st.pop();
    }
    return res;
}
int main(){
    string str;
    cin>>str;
    string result = infix_to_postfix(str);
    cout<<result<<endl;
    return 0;
}
// (a-b/c)*(a/k-l)