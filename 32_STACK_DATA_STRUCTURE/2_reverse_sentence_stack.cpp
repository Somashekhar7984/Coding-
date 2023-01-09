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
    input : hey, how are you doing?

    output : doing? you are how hey,
*/
void reverse_sentence(string str){
    int n = str.length();
    stack<string> st;

    string word = "";
    for(int i = 0;i<=n;i++){
        if(str[i] == ' ' || str[i] == '\0'){
            st.push(word);
            word = "";
            i++;
        }
        word = word + str[i];
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    string str = "hey, how are you doing?";
    reverse_sentence(str);
    return 0;
}