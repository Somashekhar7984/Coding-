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
        PREFIX EVALUATION   ==>     - + 7 * 4 5 + 2 0 --> - + 7 * 4 5 (2 + 0) --> - + 7 (4*5) (2+0) --> - (7+(4*5)) (2+0) --> ((7+(4*5))-(2+0))

        ((7+(4*5))-(2+0)) ==>   7+20 - 2 = 25

        We evaluate prefix from the back side of the string
        We use stack data structure here

            as Coming from back --> we push operend 0 and 2
                                --> then we get operator + then we pop the elements from the top and do the evaluation
                                --> after evaluation push the result to the stack

*/
// Input -->     -+7*45+20
int prefix_evaluation(string str){
    stack<int>st;
    for(int i = str.length() - 1; i>=0 ; i--){
        if(str[i]>= '0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
    int k = prefix_evaluation(str);
    cout<<k<<endl;
    return 0;
}