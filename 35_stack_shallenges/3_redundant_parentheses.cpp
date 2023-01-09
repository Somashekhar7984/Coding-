#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
//  REDUNDANT PARENTHESES
/*
    Given a vaild mathematical expression , find whether it have redundant parentheses or not .
    It contain the following operators '+','-','*','/'.

    Example :
        Input 1 :
            ((a+b))
        Output :
            1
        ((a+b)) has redundant braces so answer will be 1

        Input 2:
            (a + (a+b))
        Output:
            0
        Has No redundant parentheses . Answer will be 0
*/
bool is_operator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return true;
    }
    return false;
}
int redundant_parentheses(string str){
    int ans = 0;
    stack<char> st;
    for(int i = 0;i<str.length();i++){
        if(str[i] == '('){
            st.push(str[i]);
        }
        if(is_operator(str[i])){
            st.push(str[i]);
        }
        if(str[i] == ')'){
            if(st.top() == '('){
                ans++;
            }
            while(is_operator(st.top())){
                st.pop();
            }
            st.pop();
        }
    }
    return ans;
}
int main(){
    string str = "(((a+b)))";
    string str1 = "(a+(a+b))";
    cout<<redundant_parentheses(str)<<endl;
    return 0;
}