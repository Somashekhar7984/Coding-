#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
// Return the Size of Largest BST
/*
    Strategy:
        For Each node store the following info:
            1. min in sub tree
            2. max in sub tree
            3. subtree size
            4. size of largest BST
            5. Is_BST

    Recursively, Traverse in a bottom-up manner & find out the size of the largest BST
            (Checking From the leaves of the Tree to the Root of the tree)        
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
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool Is_BST;
};
info Largest_in_BST(struct node* root){
    if(root == NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1,root->data,root->data,1,true};
    }

    info left_info = Largest_in_BST(root->left);
    info right_info = Largest_in_BST(root->right);

    info curr_info ; // Information of current node
    curr_info.size = ( 1 + left_info.size + right_info.size );

    if(left_info.Is_BST && right_info.Is_BST && left_info.max < root->data && right_info.min > root->data){
        curr_info.min = min(left_info.min ,min(right_info.min,root->data));
        curr_info.max = max(right_info.max,max(left_info.max,root->data));
        curr_info.ans = curr_info.size;
        curr_info.Is_BST = true;
        return curr_info;
    }

    curr_info.ans = max(left_info.ans,right_info.ans);
    curr_info.Is_BST = false;

    return curr_info;
}
int main(){
    /*
           15
          /  \
        20    30
        /
       5
    */
    struct node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout<<"Largest BST in BT : "<< Largest_in_BST(root).ans<<endl;
    return 0;
}