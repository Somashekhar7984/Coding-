#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
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
/*
    Algorithm
        1. Start from the end of postorder & pick an element to create a node
        2. Decrement postorder idx
        3. Search for picked element's pos in inorder
        4. Call to build right subtree from inorder pos+1 to n
        5. Call to build left subtree from inorder 0 to pos-1
        6. Return the node
*/
int search(int arr[],int start,int end,int num){
    for(int i = start;i<=end;i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}
node* bulid_tree(int postorder[],int inorder[],int start,int end,int* idx){
    if(start > end){
        return NULL;
    }
    int curr = postorder[*idx];
    *idx = *idx - 1;
    node* node_x = new node(curr);
    if(start == end){
        return node_x;
    }
    int pos = search(inorder,start,end,curr);
    node_x->right = bulid_tree(postorder,inorder,pos+1,end,idx);
    node_x->left = bulid_tree(postorder,inorder,start,pos-1,idx);
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
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    int n = 5;
    int idx = n-1;
    node* root = bulid_tree(postorder,inorder,0,n-1,&idx);
    inorder_print(root);
    return 0;
}