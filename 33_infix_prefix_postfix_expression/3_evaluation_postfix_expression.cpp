#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int postfix_evaluation(string str){
    stack<int>st;
    for(int i = 0; i<str.length() ; i++){
        if(str[i]>= '0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(str[i]){
                case '+':{
                    st.push(op1 + op2);
                    break;
                }
                case '-':{
                    st.push(op1 - op2);
                    break;
                }
                case '*':{
                    st.push(op1*op2);
                    break;
                }
                case '/':{
                    st.push(op1/op2);
                    break;
                }
            }
        }
    }
    return st.top();
}
int main(){
    string str;
    cin>>str;
    int k = postfix_evaluation(str);
    cout<<k<<endl;
    return 0;
}
// 46+2/5*7+    --> 10 2 / 5 * 7 + --> 5 5 * 7 + --> 25 7 + --> 32