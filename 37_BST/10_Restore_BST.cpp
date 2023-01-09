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
    Problem:
            2 nodes of a BST are Swapped

            Our task is to restore or Correct the BST
*/
/*
    Strategy:
        Inorder of a BST is Sorted

            ==> 2 Elements in a sorted array are swapped 

            Case 1 :
                Swapped Elements are not adjacent to each other

                eg:
                    Original = {1,2,3,4,5,6,7,8}
                    After Swapping = {1,8,3,4,5,6,7,2}

            Case 2 :
                Swapped elements are adjacent to each other

                eg:
                    Original = {1,2,3,4,5,6,7,8};
                    After Swapping = {1,2,4,3,5,6,7,8};     


        1. Maintain 3 Pointers - First,Mid,Last

        Case 1:
            {1,8,3,4,5,6,7,2}

            First : First node where the property of sorted array is Violated at (8<3)
            Mid : next element to the First node (3)
            Last : Second node where the property of sorted array is Violated at (7<2)

            Swap First(8) with Last(2) in BST (Changing the data of the respective nodes)

        Case 2: 
            {1,2,4,3,5,6,7,8}

            First : First node where the property of sorted array is Violated at (4<3) 
            Mid : next element to the First node (3)
            Last : NULL

            if(last == NULL){
                swap(First, Mid)
            }               
*/
struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void Calculate_Pointers(struct node* root,struct node** first,struct node** mid,struct node** last,struct node** prev){
    if(root == NULL){
        return;
    }
    Calculate_Pointers(root->left,first,mid,last,prev);
    if(*prev && root->data <(*prev)->data){
        if(! (*first) ){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    Calculate_Pointers(root->right,first,mid,last,prev);
}
void Restore_BST(struct node* root){
    struct node* first,*mid,*last,*prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    Calculate_Pointers(root,&first,&mid,&last,&prev);

    // case 1
    if(first != NULL && last != NULL){
        swap(first->data,last->data);
    }
    else if(first != NULL && mid != NULL){
        swap(first->data,mid->data);
    }
}
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    else{
        return;
    }
}
int main(){
    /*
                6
               /  \
              3    9
             / \    \
            1   4    13
            
                |
                |   (Swapping 3 and 9)
                |
                v

                6
               /  \
              9    3
             / \    \
            1   4    13   
    */
   node* root = new node(6);
   root->left = new node(9);
   root->right = new node(3);
   root->left->left = new node(1);
   root->left->right = new node(4);
   root->right->right = new node(13);

   inorder(root);
   cout<<endl;
   Restore_BST(root);
   inorder(root);
   cout<<endl;
    return 0;
}