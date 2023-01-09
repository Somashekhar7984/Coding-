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
int count_nodes(struct node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + count_nodes(root->left) + count_nodes(root->right);
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
   int count = count_nodes(root);
   cout<<count<<endl;
    return 0;
}