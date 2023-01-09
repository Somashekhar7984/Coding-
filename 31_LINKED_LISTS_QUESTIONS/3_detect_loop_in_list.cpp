#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
    Floyd's Algorithm or Hare and tortoise Algorithm

    1 --> 2 --> 3 -->  4 -->  5
                      /        \
                     /          \
                    9           6
                     \         / 
                      \       /
                       8 --- 7 
    In This linked list , We could see the loop where the element 9 is connected to element 4 which is already
    present in the list

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
bool detect_cycle(node* &head){             //  if cycle is present ==> output = 1
    node* slow = head;                      //  if cycle is not present ==> output = 0
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}
void makeCycle(node* &head,int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}
void remove_cycle(node* &head){
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    fast = head;
    while(slow->next != fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;

}
int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    makeCycle(head,3);  // now the last node 6 is connected to 3
    cout<<detect_cycle(head)<<endl;
    remove_cycle(head);
    cout<<detect_cycle(head)<<endl;
    display(head);
    return 0;
}