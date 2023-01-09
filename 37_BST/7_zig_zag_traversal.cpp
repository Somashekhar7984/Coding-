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
    In Zig Zag order:
        In a tree , we print from left to right in level 1
                    we print from right to left in level 2
                    we print from left to right in level 3
                        .                    
                        .
                        .
                        So on till the last level

    Consider Tree:

                        1
                      /   \
                    2       3
                      \       \
                        4       5
                      /   \
                     6     7
    
    ZIG-ZAG :  1 3 2 4 5 7 6

    Strategy:
        1.  Use 2 Stacks - currentLevel & nextLevel
        2.  Variable Left_to_right
        3.  if Left_to_right, push leftChild then right
            else   , Push right child then left
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
void zig_zag_traversal(struct node* root){
    if(root == NULL){
        return;
    }
    stack<struct node*> curr_level;
    stack<struct node*> next_level;

    bool left_to_right = true;
    curr_level.push(root);
    while(!curr_level.empty()){
        struct node* temp = curr_level.top();
        curr_level.pop();
        if(temp != NULL){
            cout<<temp->data<<" ";
            if(left_to_right == true){
                if(temp->left != NULL){
                    next_level.push(temp->left);
                }
                if(temp->right != NULL){
                    next_level.push(temp->right);
                }
            }
            else{
                if(temp->right != NULL){
                    next_level.push(temp->right);
                }
                if(temp->left != NULL){
                    next_level.push(temp->left);
                }
            }
        }
        if(curr_level.empty()){
            left_to_right = !left_to_right;
            swap(curr_level,next_level);
        }
    }
}
int main(){
    /*
            12
          /    \
        9       15
      /   \
    5      10

    zig-zag_traversal : 12  15  9   5   10

    */
    struct node* root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);
    zig_zag_traversal(root);
    cout<<endl;
    return 0;
}