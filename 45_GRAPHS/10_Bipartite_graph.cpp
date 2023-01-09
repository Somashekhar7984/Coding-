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
// Bipartite Graph
/*
    Its vertices can be divided into two disjoint and independent sets U and V such that evry edge connects a vertex 
    in U to one in V.
    The graph does not contain any odd-length cycles
    The graph in 2 colorable.
*/
/*
    Traverse the graph
    -> Traverse the graph.
    -> If the current node is of red color,paint its neighbours as blue.

    If you are able to color the graph successfully,then the graph is bipartite.
*/

vector<vector<int>> adj;
vector<bool> visited;
vector<int> col;
bool bipart;
void color(int u,int curr){
    if(col[u] != -1 && col[u] != curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(auto i : adj[u]){
        color(i,curr^1);
        /*
            0 xor 1 = 1
            1 xor 1 = 0;
        */
    }
}
int main(){
    bipart= true;
    int n,m;
    cin>>n>>m;
    adj = vector<vector<int>> (n);
    visited = vector<bool> (n,false);
    col = vector<int> (n,-1);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            color(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is not bipartite"<<endl;
    }
    return 0;
}