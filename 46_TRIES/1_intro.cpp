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
//      TRIE --> Prefix Tree
class Trie{
    public:
        class node{
            public:
                bool end;
                node* next[26];

                node(){
                    end = false;
                    for(int i = 0;i<26;i++){
                        next[i] = NULL;
                    }
                }
        };
    node* trie;
    Trie(){
        trie = new node();
    } 


    void insert(string word){
        int i = 0;
        node* it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a']== NULL){
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    } 

    bool search(string word){
        int i = 0;
        node* it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }  
};

int main(){
    Trie mytrie;       // changing it to       Trie* mytrie;   
                        // The Code is not working
    vector<string> words = {"ayush","somashekhar"};
    for(int i =0;i<words.size();i++){
        mytrie.insert(words[i]);        // 
    }
    if(mytrie.search("shekhar")){
        cout<<"Word is exists in the Trie"<<endl;
    }
    else{
        cout<<"Word doesn't exists in the Trie"<<endl;
    }
    return 0;
}