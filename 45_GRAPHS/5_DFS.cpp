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

const int N = 1e5+2;
bool visited[N];
// Adjaceny list
vector<int> adj[N];

void dfs(int node){
    //   preorder 
            visited[node] = true;
    //      cout<<node<<" ";

    // inorder part
    vector<int> :: iterator it;
    for(it = adj[node].begin();it != adj[node].end();it++){
        if(visited[*it]){
            continue;;
        }
        else{
            dfs(*it);
        }
    }

    //post order
    cout<<node<<" ";
}
int main(){
    for(int i = 0;i<N;i++){
        visited[i] = 0;
    }

    // Taking the input for the graph
    int n,m;        // n -->  no of vertices
    cin>>n>>m;      // m -->  no of edges

    int x,y;
    for(int i = 0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // Considering the root node as one
    dfs(1);
    return 0;
}