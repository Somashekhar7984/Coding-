#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    let k = 3

    1   -->   2   -->   3 -->   4 -->   5 -->   6

   head              newtail   newhead          tail

    l = 6 (length of linked list)

    l-k = 3;    ==> new tail
    l-k + 1 = 4;    ==> new head;

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
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int length(node* head){
    int l = 0;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
node* Append_K(node* &head,int k){
    node* newhead;
    node* newtail;
    node* tail = head;

    int l = length(head);
    k = k%l;
    int count = 1;
    while(tail->next != NULL){
        if(count == l-k){
            newtail = tail;
        }
        if(count == l-k+1){
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }

    newtail->next = NULL;
    tail->next = head;

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
    display(head);
    node* new_head = Append_K(head,3);
    display(new_head);
    return 0;
}