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
int height(struct node* root){
    if(root == NULL){
        return 0;
    }
    if(1 + height(root->left) > 1 + height(root->right)){
        return 1 + height(root->left);
    }
    else{
        return 1 + height(root->right);
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
    root->left->left->left = new node(8);
    /* 
            1           ==> Level 0
          /   \
         2     3        ==> Level 1
        / \   / \
       4   5 6   7      ==> Level 2
      /
     8 
    */ 
    int h = height(root);
    cout<<h<<endl;
    return 0;
}