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
int sum_nodes(struct node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return root->data + sum_nodes(root->left) + sum_nodes(root->right);
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
            1           ==> Level 0
          /   \
         2     3        ==> Level 1
        / \   / \
       4   5 6   7      ==> Level 2

    */  
   int sum = sum_nodes(root);
   cout<<sum<<endl;
    return 0;
}