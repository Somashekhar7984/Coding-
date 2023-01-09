#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
//                  Print All nodes at distance K
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
void print_subtree_nodes(struct node* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    print_subtree_nodes(root->left,k-1);
    print_subtree_nodes(root->right,k-1);
}

// Case 2
int nodes_at_distnace_k(struct node* root,struct node* target,int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        print_subtree_nodes(root,k);
        return 0;
    }
    int dl = nodes_at_distnace_k(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            print_subtree_nodes(root->right,k-dl-2);
        }
        return 1 + dl;
    }

    int dr = nodes_at_distnace_k(root->right,target,k);
    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            print_subtree_nodes(root->left,k-dr-2);
        }
        return 1 + dr;
    }

    return -1;
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
   nodes_at_distnace_k(root,root->left,3);
    return 0;
}