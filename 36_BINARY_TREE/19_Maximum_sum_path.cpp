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
    Maximum Path Sum :
        Maximum Possible Sum of a path in the binary tree, starting & ending at any node
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
// void max_path(struct node* root,int* sum){
//     if(root == NULL){
//         return;
//     }
//     int l_sum = 0;
//     int r_sum = 0;
//     max_path(root->left,&l_sum);
//     max_path(root->right,&r_sum);
//     if(l_sum > r_sum){
//         *sum = *sum + l_sum;
//     }
//     else{
//         *sum = *sum + r_sum;
//     }
// }

/*
    Strategy:
        1.  Node val
        2.  Max path through left child + node val
        3.  Max path through right child + node val
        4.  Max path through left child + max path through right child + node val 
*/
int max_path_sum_until(struct node* root,int &ans){
    if(root == NULL){
        return 0;
    }
    int left = max_path_sum_until(root->left,ans);
    int right = max_path_sum_until(root->right,ans);

    int node_max = max(max(root->data, root->data + left + right),max(root->data + left, root->data + right));

    ans = max(ans,node_max);

    int single_path_sum = max(root->data,max(root->data + left, root->data + right));
    return single_path_sum;
}
int max_path_sum(struct node* root){
    int ans = INT_MIN;
    max_path_sum_until(root,ans);
    return ans;
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
    int sum = max_path_sum(root);
    cout<<sum<<endl;
    return 0;
}