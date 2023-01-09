#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*
   head1 ----> 1-->2-->3-->4-->5-->6-->NULL
                            /
        head2 ----> 9--> 10

    here the intersection of the linked lists is happening at 5

    The node 4 from head1 and the node 10 from head2 are pointing to the same node 5 in the further traversal

    Time complexity = O(n)
    n = max length of linked list among the two 
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
int length(node* head){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
int intersection(node* &head1,node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1;     
    node* ptr2;     

    if(l1 > l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while(d--){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
void intersect(node* &head1,node* &head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    insert_at_tail(head1,5);
    insert_at_tail(head1,6);
    insert_at_tail(head2,9);
    insert_at_tail(head2,10);
    intersect(head1,head2,5);
    display(head1);
    display(head2);

    cout<<intersection(head1,head2)<<endl;
    return 0;
}