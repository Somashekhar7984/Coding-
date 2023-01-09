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
    Sum Replacement :
        Replace the value of each node with the sum of all subtree nodesand itself
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
/*
        Brute Force : Time complexity = O(N^2)

int sum_nodes(struct node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->data + sum_nodes(root->left) + sum_nodes(root->right);
    }
}
void sum_replacement(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        root->data = sum_nodes(root);
        sum_replacement(root->left);
        sum_replacement(root->right);
    }
}*/



//          Time Complexity ==> O(N)
void sum_replacement(struct node* root){
    if(root == NULL){
        return;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->left != NULL){
        root->data = root->data + root->left->data;
    }
    if(root->right != NULL){
        root->data = root->data + root->right->data;
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
            1                                       28
          /   \         Sum Replacement            /   \
         2     3        ===============>         11     16
        / \   / \                               /  \    / \
       4   5 6   7                             4    5  6   7

    */ 
   sum_replacement(root);
   inorder(root);
   cout<<endl;
    return 0;
}