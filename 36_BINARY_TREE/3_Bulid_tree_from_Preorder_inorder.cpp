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
        Building Tree Using PREORDER and INORDER
    
    Preorder :  1 2 3
    Inorder :   2 1 3

    In Preorder ==> The first node will itself be the root of the Binary Tree
    Here What we actually do is 
            1.  we traverse the Preorder one by one
            2.  From Inorder we find it position whether it is in left subtree or right subtree of the node

    when we go to next position in the preorder , we will get 2 and we make the node 2
    Now while we traverse the Inorder ==> we encounter the node 2 before the node 1 (root node) So, it will be in left subtree of node 1

    when we go to next position in the preorder , we will get 3 and we make the node 3
    Now while we traverse the Inorder ==> we encounter the node 3 after the node 1 (root node) So, it will be in right subtree of node 1

    Hence the Final tree will be
            1
           / \
          2   3

*/
/*
    Algorithm
        1. Pick element from preorder & createanode
        2. Increment preorder idx
        3. Search for picked element's pos in inorder
        4. Call to build left subtree from inorder's 0 to pos-1
        5. Call to build right subtree from inorder pos+1 to n
        6. Return the node

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
int search(int arr[],int start,int end,int num){
    for(int i = start;i<=end;i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
node* bulid_tree(int preorder[],int inorder[],int start,int end,int* idx){
    if(start > end){
        return NULL;
    }
    int curr = preorder[*idx];
    *idx = *idx + 1;
    node* node_x = new node(curr);
    if(start == end){
        return node_x;
    }
    int pos = search(inorder,start,end,curr);

    node_x->left = bulid_tree(preorder,inorder,start,pos-1,idx);
    node_x->right = bulid_tree(preorder,inorder,pos+1,end,idx);

    return node_x;
}
void inorder_print(struct node* root){
    if(root != NULL){
        inorder_print(root->left);
        cout<<root->data<<" ";
        inorder_print(root->right);
    }
    else{
        return;
    }
}
int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int n = 5;
    int idx = 0;
    node* root = bulid_tree(preorder,inorder,0,n-1,&idx);
    inorder_print(root);
    /*
            1
          /   \
        2       3
       /       /
      4       5

    */
    return 0;
}