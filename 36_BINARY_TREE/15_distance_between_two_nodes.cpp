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
    Distance Between Two nodes : 
                    Minimum number of edges to be traversed to reach one node from the other node

    Strategy:
        1.  Find LCA
        2.  Find Distance of n1(node 1) and n2(node 2) from LCA
        3.  return d1(for n1) + d2(for n2)                 
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
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);

}
int find_distance(struct node* root,int k,int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }
    int left = find_distance(root->left,k,dist + 1);
    if(left != -1){
        return left;
    }
    return find_distance(root->right,k,dist + 1);
}
int distance(struct node* root,int n1,int n2){
    struct node* lca = LCA(root,n1,n2);
    int d1 = find_distance(lca,n1,0);
    int d2 = find_distance(lca,n2,0);
    return d1 + d2;
}
int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<distance(root,3,5)<<endl;
    /* 
            1
          /   \
         2     3
        / \   / \
       4   5 6   7

    */  
    return 0;
}