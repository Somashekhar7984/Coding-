#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    Given linked list : 1 --> 2 --> 3 --> 4 --> 5 --> 6
                        |     |
                       odd   even

    result :    1 --> 3 --> 5 --> 2 --> 4 --> 6 
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
void even_after_odd_nodes(node* &head){
    node* odd = head;
    node* even = head->next;
    node* even_start = even;
    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;
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

    even_after_odd_nodes(head);

    display(head);
    return 0;
}