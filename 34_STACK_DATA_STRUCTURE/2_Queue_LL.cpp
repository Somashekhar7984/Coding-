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
    LINKED LIST IMPLEMENTATION of QUEUE
*/
class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

class queue{
    node* front;
    node* back;

    public:
        queue(){
            front = NULL;
            back = NULL;
        }

        void push(int x){
            node* n = new node(x);
            if(front == NULL){
                back = n;
                front = n;
                return;
            }
            back->next = n;
            back = n;
        }

        void pop(){
            if(front == NULL){
                cout<<"No elements in Queue"<<endl;
                return;
            }
            node* to_delete = front;
            front = front->next;
            delete to_delete;
        }

        int peek(){
            if(front == NULL){
                cout<<"No elements in Queue"<<endl;
                return -1;
            }
            return front->data;
        }

        bool empty(){
            if(front == NULL){
                return true;
            }
            return false;
        }
};
int main(){
    queue Q;
                 //     Queue :     Empty
     Q.push(1);  //     Queue : 1
     Q.push(2);  //     Queue : 1 2
     Q.push(3);  //     Queue : 1 2 3
     Q.push(4);  //     Queue : 1 2 3 4

    cout<<Q.peek()<<endl;   // Prints 1
    Q.pop();                // Removes 1    Queue : 2 3 4
    cout<<Q.peek()<<endl;   // Prints 2
    Q.pop();                // Removes 2    Queue : 3 4
    cout<<Q.peek()<<endl;   // Prints 3
    Q.pop();                // Removes 3    Queue : 4
    cout<<Q.peek()<<endl;   // Prints 4
    Q.pop();
    cout<<Q.empty()<<endl;   
    return 0;
}