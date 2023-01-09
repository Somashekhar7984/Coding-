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
//   CYCLE DETECTION IN AN UN-DIRECTED GRAPH

/*
    Whenever we get a visited node(Or any back Edge) in the traversing the graph then we can say that the graph has cycle 

    Keep on traversing the graph
    If you found an edge pointing to an already visited node(except the parent node), a cycle is found.
*/
bool is_cycle(int src,vector<vector<int>> &adj,vector<bool> &visited,int parent){
    visited[src] = true;
    for(auto i : adj[src]){
        if(i != parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] && is_cycle(i,adj,visited,src)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n);

    // UN-DIRECTED GRAPH
    for(int i = 0;i<m;i++){
        // u <--> v (Un-directed edge)
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle = false;
    vector<bool> visited(n,false);
    for(int i = 0;i<n;i++){
        if(visited[i] == false && is_cycle(i,adj_list,visited,-1)){
            cycle = true;
        }
    }
    if(cycle){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }

    return 0;
}