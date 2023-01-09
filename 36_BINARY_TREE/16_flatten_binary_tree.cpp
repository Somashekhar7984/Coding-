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
    Given a binary tree , flatten it into linked list in place. After flattening , left of each node should point 
    to NULL and right should contain next node in preorder sequenece

    (It's NOT allowed to use other data structures)

      Binary Tree                   Flat Binary Tree

          1                             1
        /   \                            \
       2     3                            2
            /                              \
           4                                3
                                             \
                                              4

    Strategy:
        1.  Recursively , Flatten the left & right subtree  
        2.  Store left tail and right tail.
        3.  Store right subtree in temp & make left subtree as right subtree
        4.  Join right subtree with left tail
        5.  Return right tail
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
void flatten(struct node* root){
    // if(root == NULL){
    //     return;
    // }
    // if(root->left != NULL){
    //     flatten(root->left);
    // }
    // flatten(root->right);
    // struct node* left_tail = root->left;
    // while(left_tail->right != NULL){
    //     left_tail = left_tail->right;
    // }
    // struct node* right_tail = root->right;
    // while(right_tail->right != NULL){
    //     right_tail = right_tail->right;
    // }
    // struct node* temp = root->right;
    // root->right = root->left;
    // root->left = NULL;
    // left_tail->right = temp;

    // return right_tail;
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->left != NULL){
        flatten(root->left);

        struct node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        struct node* selected = root->right;
        while(selected->right != NULL){
            selected = selected->right;
        }
        selected->right = temp;
    }
    flatten(root->right);
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
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    /* 
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    */ 
   flatten(root);
   inorder(root);
   cout<<endl;
    return 0;
}