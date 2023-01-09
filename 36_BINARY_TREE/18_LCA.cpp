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
struct node* LCA(struct node* root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    struct node* left = LCA(root->left,n1,n2);
    struct node* right = LCA(root->right,n1,n2);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left != NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
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
   struct node* lca = LCA(root,6,7);
   cout<<lca->data<<endl; 
    return 0;
}