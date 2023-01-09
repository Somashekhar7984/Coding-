#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
        Reverse the linked list
        Time complexity = O(n)        n -->
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
    node* selected = head;
    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        return;
    }
    while(selected->next != NULL){
        selected = selected->next;
    }
    selected->next = temp;
}
void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// Iterative way of reversing a linked list
node* reverse_linked_list(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL){
        // changing the pointing direction of the pointer
        nextptr = currptr->next;
        currptr->next = prevptr;

        // moving the pointers to the next node to it
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
// Recursive way of reversing the linked list
node* reverseRecursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
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
    display(head);
    node* newhead = reverse_linked_list(head);
    display(newhead);
    node* newhead1 = reverseRecursive(newhead);
    display(newhead1);
    return 0;
}