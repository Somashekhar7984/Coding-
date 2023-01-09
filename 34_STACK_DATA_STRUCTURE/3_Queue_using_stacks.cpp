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
    Approach 1:
        Two stacks and dequeue is costly
        Enqueue Operation:
                push x into stack 1

        Dequeue Operation:
            1.  if both stcaks are empty then print error
            2.  if stack 2 is empty
                        while stack 1 is not empty push everything from stack 1 to stack 2 
            3.  Pop the element from ha stack 2 and return it

                                   push         
                                    |
      stack 1 :     1 2 3 4 5 6  ----
                                    |
                                   pop

      stack 2 :     6 5 4 3 2 1                 // Removing and adding into other stack results in Reverse of stack

                    now pop from stack 2 results as the pop from the stcak 1 from the front side (same as in Queue)


*/
class queue{
    stack<int> st1;
    stack<int> st2;

    public:
        void push(int x){
            st1.push(x);
            return;
        }

        int pop(){
            if(st1.empty() && st2.empty()){
                cout<<"Queue is empty "<<endl;
                return -1;
            }
            if(st2.empty()){
                while(!st1.empty()){
                    int k = st1.top();
                    st1.pop();
                    st2.push(k);
                }
            }
            int k = st2.top();
            st2.pop(); 
            return k;   
        }
        bool empty(){
            if(st1.empty() && st2.empty()){
                return true;
            }
            return false;
        }
};
int main(){
    queue Q;    
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    cout<<Q.pop()<<endl;
    Q.push(5);
    cout<<Q.pop()<<endl;
    cout<<Q.pop()<<endl;
    cout<<Q.pop()<<endl;
    cout<<Q.pop()<<endl;
    cout<<Q.pop()<<endl;
    return 0;
}