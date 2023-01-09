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
    Balanced Height Tree
        For each node, The difference between the heights of the left subtree and right subtree <= 1

        Mod(left subtree - right subtree) = 1
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
int height(struct node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + max(height(root->left),height(root->right));
    }
}
bool is_balanced(struct node* root){    // Time Complexity ==> O(N^2)
    if(root == NULL){
        return true;
    }
    if(is_balanced(root->left) == false){
        return false;
    }
    if(is_balanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}
// Time Complexity ===> O(N)
bool is_balanced2(struct node* root,int* height){
    if(root == NULL){
        *height = 0;
        return true;
    }
    int lh = 0;
    int rh = 0;
    if(is_balanced2(root->left,&lh) == false){
        return false;
    }
    if(is_balanced2(root->right,&rh) == false){
        return false;
    }
    *height = max(lh,rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
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
            1                                       
          /   \        
         2     3       
        / \   / \                              
       4   5 6   7                             

    */ 
    if(is_balanced(root)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Not Balanced Tree"<<endl;
    }
    int height = 0;
    if(is_balanced2(root,&height)){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Not Balanced Tree"<<endl;
    }
    return 0;
}