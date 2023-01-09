#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
#define n 100
/*
    STACK:
        Stores a list of items in which an item can be added or removed from the list only at one end
    LIFO ===> LAST IN FIRST OUT

    Operations:
        push(x) --> Insert at the top of the stack
        pop()   --> remove an element from the top of the stack
        top()   --> return the top element in the stack
        empty() --> checks whether the stack is empty or not

    All operations are O(1) time {constant time}    

*/
class stack{
    int* arr;
    int top;
    public:
        stack(){
            arr = new int[n];
            top = -1;
        }

        void push(int x){
            if(top == n-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;
            arr[top] = x;
        }

        void pop(){
            if(top == -1){
                cout<<"No element in stack to pop"<<endl;
                return;
            }
            top--;
        }

        int Top(){
            if(top == -1){
                cout<<"No element in stack"<<endl;
                return -1;
            }
            return arr[top];
        }

        bool empty(){
            return (top == -1);
        }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}