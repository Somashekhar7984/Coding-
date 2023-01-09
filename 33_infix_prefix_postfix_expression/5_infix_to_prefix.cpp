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
                        INFIX TO PREFIX
        ( a - b / c ) * ( a / k - l )   
    1.    First of all reverse the string  ===> ) l - k / a ( * ) c / b - a (
    2.    After This replace open bracket '(' with closing bracket ')'
                           and close bracket ')' with open bracket '('
                        ( l - k / a ) * ( c / b - a )
    3.    now do the conversion as same infix to postfix
                        l k a / - c b / a - *
    4.    now reverse the final string to get the prefix form of the infix expression  
                        * - a / b c - / a k l                                          
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
string infix_to_prefix(string str){
    stack<char> st;
    string res = "";
    reverse(str.begin(),str.end());
    for(int i = 0;i<str.length();i++){
        if( (str[i] >= 'a' && str[i] <= 'z') || ( str[i] >= 'A' && str[i] <= 'Z') ){
            res = res + str[i];
        }
 /* 1 */else if(str[i] == ')'){         // Here instead of reversing the brackets in the string at the beginning
            st.push(str[i]);            // we changed the 'if' conditions '(' to ')'
        }                               //                                ')' to '('
 /* 2 */else if(str[i] == '('){         //      made changes as above mentioned at 1,2,3 
    /* 3 */while(!st.empty() && st.top() != ')'){
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
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    string str;
    cin>>str;
    string result = infix_to_prefix(str);
    cout<<result<<endl;
    return 0;
}
//  (a-b/c)*(a/k-l) 