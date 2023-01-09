#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
        ------------------------
        |                       |
        v                       |
        1--->2--->3--->4--->5---
        ^
        |
       head 

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
void insert_at_head(node* &head,int val){
    node* temp = head;
    node* n = new node(val);

    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }

    while(temp->next!= head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}
void insert_at_tail(node* &head,int val){
    if(head == NULL){
        insert_at_head(head,val);
        return;
    }
    node* selected = head;
    node* temp = new node(val);

    while(selected->next != head){
        selected = selected->next;
    }

    selected->next = temp;
    temp->next = head;
}
void display(node* &head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
void delete_at_head(node* &head){
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    node* to_delete = head;
    temp->next = head->next;

    head = head->next;

    delete to_delete;

}
void deletion(node* &head,int pos){
    if(pos == 1){
        delete_at_head(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count != pos - 1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);
    insert_at_head(head,5);
    display(head);

    deletion(head,1);
    display(head);
    return 0;
}