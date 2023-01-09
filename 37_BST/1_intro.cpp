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
    BST ==> Binary search tree

    Rules:
        1.  The left subtree of a node contains only nodes with datas lesser than the node's data
        2.  The right subtree of a node contains only nodes with datas greater than the node's data.
        3.  The left and right subtrees each must also be a binary search tree. There must be no duplicate nodes in BST
    Eg:

                         3
                       /  \
                     2      7
                    /      /  \
                  1       5    8
                        /   \
                       4     6

    Buliding a BST from an array:
            5 1 3 4 2 7

                    5
                  /    \
                1       7
                  \
                   3
                  /  \
                2     4


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
node* insertBST(node* root,int val){
    if(root == NULL){
        return new node(val);
   }
    if(val < root->data){
        root->left=insertBST(root->left,val);
    }else{
       // val>root->data
        root->right=insertBST(root->right,val);
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
struct node* search(struct node* root,int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(val < root->data){
        return search(root->left,val);
    }
    return search(root->right,val);
    //return root;
}
int main(){
    struct node* root = NULL;
    root = insertBST(root,5);
    root = insertBST(root,1);
    root = insertBST(root,3);
    root = insertBST(root,4);
    root = insertBST(root,2);
    root = insertBST(root,7);
    inorder(root);
    cout<<endl;
    struct node* temp = search(root,5);
    if(temp == NULL){
        cout<<"Element is not present"<<endl;
    }
    else{
        cout<<temp->data<<endl;
    }
    return 0;
}