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
    we are provided with the preorder sequence of the tree,
    we know that in a BST the inorder sequence is a sorted sequence 
        Hence sorting the preorder sequence gives the inorder sequence

    Now having both the inorder and preorder sequence     

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
// BASIC code for constructing the tree from preorder and inorder
int search(int arr[],int num,int start,int end){
    for(int i = start; i<=end ; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
struct node* build_tree(int inorder[],int preorder[],int start,int end,int* idx){
    // we can get the inorder sequence by sorting the preorder array
    if(start > end){
        return NULL;
    }
    int curr = preorder[*idx];
    *idx = *idx + 1;
    struct node* node_x = new node(curr);
    if(start == end){
        return node_x;
    }
    int pos = search(inorder,curr,start,end);
    node_x->left = build_tree(inorder,preorder,start,pos - 1,idx);
    node_x->right = build_tree(inorder,preorder,pos + 1,end,idx);
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

// Single Recursive function 
struct node* constructBST(int preorder[],int* preorder_idx,int key,int min,int max,int n){
    if(*preorder_idx >= n){
        return NULL;
    }
    struct node* root = NULL;
    if(key > min && key < max){
        root = new node(key);
        *preorder_idx = *preorder_idx + 1;

        if(*preorder_idx < n){
            root->left = constructBST(preorder,preorder_idx,preorder[*preorder_idx],min,key,n);
        }
        if(*preorder_idx < n){
            root->right = constructBST(preorder,preorder_idx,preorder[*preorder_idx],key,max,n);
        }
    }
    return root;
}
int main(){
    /*
                10
               /  \
              2   13
             /    /
            1    11
    */
   int preorder[] = {10,2,1,13,11};
   int n = 5;
   int preorder_idx = 0;
   struct node* root = constructBST(preorder,&preorder_idx,preorder[0],INT_MIN,INT_MAX,n);
   inorder_print(root);
    return 0;
}