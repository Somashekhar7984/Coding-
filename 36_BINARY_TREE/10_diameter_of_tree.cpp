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
    Diameter : Number of nodes in the longest path between any two leaves

    Intution:
        max(left height + right height + 1, left diameter , right diameter)
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
    return 1 + max(height(root->left) , height(root->right));
}
int diameter(struct node* root){    // ===> O(N^2)
    if(root == NULL){
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    int currDiameter = hl + hr + 1;

    int Ldiameter = diameter(root->left);
    int Rdiameter = diameter(root->right);
    return max(currDiameter,max(Ldiameter,Rdiameter));
}
int dia_optimised(struct node* root,int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int Ldiameter = dia_optimised(root->left,&lh);
    int Rdiameter = dia_optimised(root->right,&rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDiameter,max(Ldiameter,Rdiameter));
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
   int diameter_of_tree = diameter(root);
   cout<<diameter_of_tree<<endl;
   int height = 0;
   int dia_optim = dia_optimised(root,&height);
   cout<<dia_optim<<endl;
    return 0;
}