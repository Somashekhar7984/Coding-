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
        Properties in Binary Tree
        1.  Maximum nodes in a level L = 2^L
        2.  Maximum nodes in a tree of height H is === 2^H - 1
        3.  For N nodes , minimum possible height or minimum number of levels are Log(N+1) (base = 2)
        4.  A binary tree with L leaves has at least Log(N+1)+1 number of levels

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

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

   /*     1
         / \
        2   3
   */ 

    root->left->left = new node(4);
    root->left->right = new node(5);
    /* 
           1
          / \
         2   3
        / \
       4   5

   */  
    root->right->left = new node(6);
    root->right->right = new node(7);
     /* 
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

   */  
    return 0;
}