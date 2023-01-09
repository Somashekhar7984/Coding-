#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
/*
    Given a binary tree in an array representation
        10,7,4,3,11,14,6

                10              parent = i;
               /  \            left = 2*i + 1;
              7     4           right = 2*i + 2;
             / \   / \
            3   11/   6
                14


    Computing Horizontal Distance Approach:
            The distance at the centre of the tree(at root) = 0

    then
        HD(Horizontal Distance){3} = -2;
        HD(Horizontal Distance){7} = -1;
        HD(Horizontal Distance){10,11,14} = 0;
        HD(Horizontal Distance){4} = 1;
        HD(Horizontal Distance){6} = 2;
    Using Hashing:
        1 -> Starting from root node
        2 -> Recursively call left and right with (HD - 1) and (HD + 1) as arguments
                Base Case => when current node = NULL ( Return )
        3 -> Push the value into vector corresponding to the horizontal distance(HD)

        key(HD)
          0         10, 11, 14
          -1        7
          -2        3
          1         4
          2         6
*/ 
struct node{
    int key;
    struct node* left;
    struct node* right;

    node(int val){
        key = val;
        left = NULL;
        right = NULL;
    }
};
void Get_vertical_order(struct node* root,int HD,map<int,vector<int>> &mp){
    if(root == NULL){
        return;
    }
    mp[HD].push_back(root->key);
    Get_vertical_order(root->left,HD-1,mp);
    Get_vertical_order(root->right,HD+1,mp);
}

int main(){
    node* root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(6);
   // root->left->right->right = new node(100);

//  map<first,second> name;
    map<int,vector<int>> mp;
    int HD = 0;

    Get_vertical_order(root,HD,mp);
    map<int,vector<int>> :: iterator it;
    for(it = mp.begin();it != mp.end();it++){
        cout<<it->first<<" ";
        for(int i = 0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"The Top View of the binary tree"<<endl;
// For the Top view of the binary tree
    for(it = mp.begin();it != mp.end();it++){
        cout<<it->second[0]<<" ";
    }
    return 0;
}