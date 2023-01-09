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
    For given root nodes of 2 binary search trees, print of the BSTs are identical or not

        Identical BST's are structurally identical && have equal values for nodes in the structure

        strategy:
            1.  if both are empty, return true;
            2.  if(both non empty)
                    a.  check that the data at nodes is equal
                    b.  check if left_subtrees are same
                    c.  check if right_subtrees are same
            3.  if(a,b,c are true), return true
                    else    return false;        
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
bool identical_BST(struct node* root1,struct node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        bool left = identical_BST(root1->left,root2->left);
        bool right = identical_BST(root1->right,root2->right);
        if(root1->data == root2->data && left && right){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    struct node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);
    /*
            2   
          /   \
        1       3
    */
    if(identical_BST(root1,root1)){
        cout<<"Identical Trees"<<endl;
    }
    else{
        cout<<"Not Identical Trees"<<endl;
    }
    struct node* root2 = new node(6);
    root2->left = new node(5);
    root2->right = new node(7);
    /*
            6
          /   \
        5       7
    */
    if(identical_BST(root1,root2)){
        cout<<"Identical Trees"<<endl;
    }
    else{
        cout<<"Not Identical Trees"<<endl;
    }
    return 0;
}