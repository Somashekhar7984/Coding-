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
    Approach 1:
        node > left_child   &&  node < right_child  ==> ALL nodes    ======>    WRONG APPROACH

    Approach 2:
        maximum of left subtree (maxL) < node 
                    &&
        minimum of right subtree (minR) > node  

    Approach 3:
        min allowed && max allowed  ===> Traverse only once

    Strategy:

                node(min,max)
                /           \
               /             \
        left(min,node)    right(node,max)      

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

bool check_BST(struct node* root,struct node* min,struct node* max){    // Time complexity ==> O(N)  N = no of nodes
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool left = check_BST(root->left,min,root);
    bool right = check_BST(root->right,root,max);
    if(left == true && right == true){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    struct node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);

    struct node* min = new node(INT_MIN);
    struct node* max = new node(INT_MAX);
    cout<<check_BST(root1,min,max)<<endl;
    return 0;
}