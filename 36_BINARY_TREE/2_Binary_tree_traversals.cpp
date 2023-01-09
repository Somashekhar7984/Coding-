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
    Preorder Traversal
        Root
        left subtree
        right subtree

    Inorder Traversal
        left subtree
        root
        right subtree

    Postorder Traversal
        left subtree
        right subtree
        root

                    1
                  /   \
                2       3
              /   \    /  \
             4     5  6    7          

    Preorder :  1 2 4 5 3 6 7
    Inorder :   4 2 5 1 6 3 7
    Postorder : 4 5 2 6 7 3 1
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
void preorder(struct node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    else{
        return;
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
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
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
   preorder(root);
   cout<<endl;
   inorder(root);
   cout<<endl;
   postorder(root);
    return 0;
}