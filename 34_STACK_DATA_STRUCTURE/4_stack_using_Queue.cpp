#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
//#include<stack>
#include<queue>
// Using a Single Queue 
/*
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0;i<q.size() - 1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
*/
using namespace std;
/*
    Approach 1:
        Two queues and pop Operation will be costly

*/
class stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
        stack(){
            N = 0;
        }

        void pop(){
            if(q1.empty()){
                return;
            }
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            N--;

            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
        }

        void push(int x){
            q1.push(x);
            N++;
        }

        int top(){
            if(q1.empty()){
                return -1;
            }
            else{
                while(q1.size() != 1){
                    q2.push(q1.front());
                    q1.pop();
                }
                int ans = q1.front();
                q2.push(q1.front());
                q1.pop();

                queue<int> temp = q1;
                q1 = q2;
                q2 = temp;
                
                return ans;
            }
        }
        int size(){
            return N;
        }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}