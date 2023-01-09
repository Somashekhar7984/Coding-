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
    Catalan Numbers :   sequence of natural numbers that occur in various counting problems,often involving recursively
                        defined object

                Mathematical Form of Catalan Numbers :

                        Cn = (1/(n+1)) 2nCn = sigma(Cn*Cn-i), for i = 0 to n-1

    C0 = 1
    C1 = 1
    C2 = C0*C1 + C1*C0 = 1 + 1 = 2
    C3 = C0*C2 + C1*C1 + C2*C0 = 1*2 + 1*1 + 2*1 = 5
    C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0 = 1*5 + 1*2 + 2*1 + 5*1 = 5 + 2 + 2 + 5 = 14

*/
//          CODE TO FIND Nth CATALAN NUMBER

//      Time Complexity ==> O(N^2)
int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int result = 0;
    for(int i = 0;i<n;i++){
        result = result + catalan(i)* catalan(n-i-1);
    }
    return result;
}
/*
    Applications of Catalan Numbers :
    1.  Possible BSTs
            n = 3 ;;;  where n is no of nodes in the tree

            then No of BSTs that can be formed  C3 = 5

                        No of Possible BST

            n = 1 ==>    1          ==> 1
            n = 2 ==>    1    1     ==> 2
                        /      \
                       2        2


    2.  Paranthesis/Bracket Combinations
    3.  Possible Forests
    4.  Ways of Triangulations
    5.  Possible Paths in Matrix
    6.  Dividing a circle Using N Chords
    7.  Dyck Words of given length & much more
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
vector<struct node*> Construct_tree(int start,int end){
    vector<struct node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i = start;i<=end;i++){
        vector<struct node*> leftsubtrees = Construct_tree(start,i-1);
        vector<struct node*> rightsubtrees = Construct_tree(i+1,end);

        for(int j = 0;j<leftsubtrees.size();j++){
            struct node* left = leftsubtrees[j];
            for(int k = 0;k<rightsubtrees.size();k++){
                struct node* right = rightsubtrees[k];
                struct node* node_x = new node(i);
                node_x->left = left;
                node_x->right = right;
                trees.push_back(node_x);
            }
        }
    }
    return trees;
}
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    // for(int i = 0;i<10;i++){
    //     cout<<catalan(i)<<" ";
    // }

    vector<struct node*> Total_trees = Construct_tree(1,3);
    for(int i = 0;i<Total_trees.size();i++){
        cout<<i+1<<" ; ";
        preorder(Total_trees[i]);
        cout<<endl;
    }
    return 0;
}