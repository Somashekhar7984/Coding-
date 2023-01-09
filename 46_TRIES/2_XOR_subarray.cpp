#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;
//  Tries --> Maximum XOR of Two Numbers in an array
/*
    Array = [3,10,5,15,2]

    Brute Force:
    int max_ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            max_ans = max(max_ans,ans[i]^ans[j]);
        }
    }
    return max_ans;


    To Maximize XOR

        0 XOR 0  =  0
        0 XOR 1  =  1 
        1 XOR 0  =  1
        1 XOR 1  =  0 


    X  = 0xBBBBB    --> To Maximize XOR : we try to move to move in opposite direction, if possible
    Array = [3,10,5,15,2]
        00011   01010   00101   01111   00010
*/
// Some Error is there in the code
class TrieNode{
    public:
        TrieNode* next[2];
        TrieNode(){
            next[0] = NULL;
            next[1] = NULL;
        }
};
TrieNode* buildTrie(vector<int> &v){
    TrieNode* root = new TrieNode();
    int n = v.size();
    for(int i = 0;i<n;i++){
        int num = v[i];

        TrieNode* curr = new TrieNode();
        for(int i = 31;i>=0;i--){
            int bit = (num>>i & 1);
            if(curr->next[bit] == NULL){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}
int helper(TrieNode* root,vector<int> &a){
    int res = 0;
    for(int i = 0;i<a.size();i++){
        int num = a[i];
        TrieNode* it = root;
        int curr_max = 0;
        for(int i = 31;i>=0;i--){
            int bit = ((num>>i) & 1) ? 0 : 1;
            if(it->next[bit]){
                curr_max <<= 1;
                curr_max = curr_max | 1;
                it = it->next[bit];
            }
            else{
                curr_max <<= 1;
                curr_max |= 0;
                it = it->next[bit^1];
            }
        }
        res = max(res,curr_max);
    }
    return res;
}
int main(){
    vector<int> v = {3,10,5,15,2};
    TrieNode* root = buildTrie(v);
    int ans = helper(root,v);
    cout<<ans<<endl;
    return 0;
}