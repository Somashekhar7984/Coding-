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
    Given a sorted array:

                        2
        [1,2,3] ====>  / \
                      1   3

    startegy:
        1. Make middle element the root
        2. Recursively, Do the same for subtrees
                    a. start to mid - 1 for left subtree
                    b. mid + 1 to end for right subtree            
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
struct node* sorted_array_to_BST(int arr[],int start,int end){
    if(start > end){
        return NULL;
    }
    int mid = ( start + end )/2;
    struct node* root = new node(arr[mid]);
    root->left = sorted_array_to_BST(arr,start,mid - 1);
    root->right = sorted_array_to_BST(arr,mid + 1,end);
    return root;
}
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int arr[] = {10,20,30,40,50};
    struct node* root = sorted_array_to_BST(arr,0,4);
    preorder(root);
    return 0;
}