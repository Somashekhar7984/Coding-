#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
/*
    In this program we reverse the nodes K nodes
    eg :    1-->2-->3-->4-->5-->6
    if K = 2

    the final list will be 
            2-->1-->4-->3-->6-->5

            Here the first K nodes will be reversed as (1-->2) to (2-->1)
                                                       (3-->4) to (4-->3)
                                                       () 
    
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
node* reverse_k_nodes(node* &head,int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    // Here the first K nodes will be reversed by the following code
    int count = 0;
    while(currptr != NULL && count < k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    // Now for the remaining elements in the linked list
    // The function is called recursively
    if(nextptr != NULL){
        head->next = reverse_k_nodes(nextptr,k);
    }
    return prevptr;
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
    int k;
    cout<<"Enter a number < 7 : "<<endl;
    cin>>k;
    display(head);
    node* newhead = reverse_k_nodes(head,k);
    display(newhead);
    return 0;
}