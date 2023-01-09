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
                    STACK DATA STRUCTURE

        Stores a list of items in which an item can be inserted at one end and removed from the other end only

        FIFO  ==> First In First Out

    In stcak we use a pointer for tracking of stack ==> Top
    In Queue we use tw0 pointers for tracking of queue ==>  Front and Back

    Operations:
        enqueue(x)  --> Adds or inserts at the back of the queue \\ similar to push in stack
        dequeue()   --> delete the element from the front of queue \\ similar to pop in stack
        peek()      --> returns front value in the queue
        empty()     --> checks whether queue is empty or not

*/
#define n 20
class queue{
    int* arr;
    int front;
    int back;
    public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }
        void push(int x){
            if(back == n-1){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            back++;
            arr[back] = x;
            if(front == -1){
                front++;
            }
        }
        void pop(){
            if(front == -1 || front > back){
                cout<<"No elements in Queue"<<endl;
                return;
            }
            front++;
        }
        int peek(){
            if(front == -1 || front > back){
                cout<<"No elements in Queue"<<endl;
                return -1;
            }
            return arr[front];
        }
        bool empty(){
            if(front == -1 || front > back){
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