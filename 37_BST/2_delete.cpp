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
    CASE 1  :   node is a leaf
    CASE 2  :   node has only one child
    CASE 3  :   node has two children
                Step 1 :
                    find the Inorder successor of the node that need to be deleted
                Step 2 :
                    Replace node with inorder successor
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
struct node* inorder_successor(struct node* root){
    struct node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
struct node* delete_BST(struct node* root,int key){
    if(key < root->data){
        root->left = delete_BST(root->left,key);
    }
    else if(key > root->data){
        root->right = delete_BST(root->right,key);
    }
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // CASE 3

        struct node* temp = inorder_successor(root->right);
        root->data = temp->data;
        root->right = delete_BST(root->right,temp->data);
    }
    return root;
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
    struct node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);
    /*
             4
           /   \
          2      5
         / \      \
        1   3       6
    */
   inorder(root);
   cout<<endl;
   root = delete_BST(root,2);
   inorder(root);
    return 0;
}