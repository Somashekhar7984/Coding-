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
            BALANCED PARENTHESIS

     string ===> {([])} --> Balanced parenthesis
                 {([]}) --> Not Balanced parenthesis       
*/
bool check_balance(string str){
    stack<char> st;
    int n = str.length();
    bool ans = true;
    for(int i = 0;i<n;i++){
        if(str[i] == '{' || str[i] == '(' || str[i] == '['){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(str[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(str[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    return ans;
}
int main(){
    string str;     // {([])}
    cin>>str;
    cout<<check_balance(str)<<endl;
    return 0;
}