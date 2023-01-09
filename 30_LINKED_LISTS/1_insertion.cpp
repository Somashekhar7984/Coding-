#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
//                  LINKED LIST
/*
                 array                         |      linked list
    1. single block of memory with paritions   |    1. Multiple blocks of memory linked to each other
    Limitations                                |    Properties 
       -> Fixed size                           |        -> size can be modified 
       -> Contiguous block of memory           |        -> Non-contiguous memory
       -> Inserting or deleting is costly      |        -> Insertion and deletion at any point is easier


    Block of memory = NODE

    node : 
         int data
         node pointer of next node 
    head pointer : 
        stores the address of the starting node
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

void insert_at_tail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void insert_at_head(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head){
    node* temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
bool search(node* head,int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_head(head,9);
    display(head);
    cout<<search(head,10)<<endl;
    cout<<search(head,3)<<endl;

    return 0;
}