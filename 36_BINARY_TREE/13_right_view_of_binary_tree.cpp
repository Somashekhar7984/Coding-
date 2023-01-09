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
/*

                    1
                  /   \                 ==> Right View == 1 3 6 7
                2       3               ==> Left View == 1 2 4 7
              /       /   \
            4       5       6
                  / 
                7

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
void right_view(struct node* root){
  // if(root == NULL){
  //   return;
  // }
  //   queue<struct node*> Q;
  //   Q.push(root);
  //   Q.push(NULL);
  //   cout<<root->data<<" ";
  //   while(!Q.empty()){
  //     struct node* node_x = Q.front();
  //     Q.pop();
  //     if(node_x != NULL){
  //         if(node_x->right != NULL){
  //           Q.push(node_x->right);
  //         }
  //         if(node_x->right != NULL){
  //           Q.push(node_x->left);
  //         }
  //     }
  //     else if(!Q.empty()){
  //       struct node* temp = Q.front();
  //       cout<<temp->data<<" ";
  //       Q.push(NULL);
  //     }
  //   }
  if(root == NULL){
    return;
  }
  queue<struct node*> Q;
  Q.push(root);

  while(!Q.empty()){
    int n = Q.size();
    for(int i = 0;i<n;i++){
      struct node* temp = Q.front();
      Q.pop();
      if(i == n-1){
        cout<<temp->data<<" ";
      }
      if(temp->left != NULL){
        Q.push(temp->left);
      }
      if(temp->right != NULL){
        Q.push(temp->right);
      }
    }
  }

}
int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    right_view(root);
    cout<<endl;
    return 0;
}