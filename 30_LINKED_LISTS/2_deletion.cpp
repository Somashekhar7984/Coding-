#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head,int val){
    node* temp = new node(val);
    node* selected = head;
    if(selected != NULL){
        while(selected->next != NULL){
            selected = selected->next;
        }
        selected->next = temp; 
    }
    else{
        head = temp;
    }
}

void display(node* &head){
    node* selected = head;
    while(selected != NULL){
        cout<<selected->data<<" ";
        selected = selected->next;
    }
    cout<<endl;
}

void delete_at_head(node* &head){
    node* to_delete = head;
    head = head->next;

    delete to_delete;
}

void deletion(node* &head,int val){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        head = NULL;
        return;
    }

    node* selected = head;
    while(selected->next->data != val){
        selected = selected->next;
    }
    node* to_delete = selected->next;
    selected->next = selected->next->next;

    delete to_delete;
}

int main(){
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head ,4);
    display(head);
    // Deletion operation is explained in this code

    //deletion(head, 3);
    delete_at_head(head);
    display(head);
    return 0;
}