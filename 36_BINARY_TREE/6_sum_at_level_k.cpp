#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
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
int sum_level_k(struct node* root,int level){
    queue<struct node*> Q;
    Q.push(root);
    Q.push(NULL);
    int k = 0;
    int sum = 0;
    while(!Q.empty()){
        struct node* x = Q.front();
        Q.pop();
        if(x != NULL){
            if(k == level){
                sum = sum + x->data;
            }
            if(x->left != NULL){
                Q.push(x->left);
            }
            if(x->right != NULL){
                Q.push(x->right);
            }
        }
        else if(!Q.empty()){
            Q.push(NULL);
            k++;
        }
    }
    return sum;
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
   int level = 1;
    int res = sum_level_k(root,level);
    cout<<res<<endl;
    return 0;
}