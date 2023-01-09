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
// Connected Components in the graph
/*
    A Connected Component is a subgraph in which any two vertices are connected to each other by paths,
    and which is connected to no additional vertices in the supergraph.

    Idea:
        1. Visit the nodes in a depth-first fashion
        2. If the node is not visited,visit that node and its neighbour recursively.

    Each time a un-visited node is found , a new component will be found.
*/
/*
    Pseudocode:
    For node u in nodes:
        if(vis[u] == false){
            components.add(visit_components(u));
        }
    
    function visit_component(src){
        vis[src] = true;
        for v in adj[src]
            visit_component(v);
    }
*/
vector<bool> visited;
int n,m;
vector<vector<int>> adj;
vector<int> components;
int get_comp(int idx){
    if(visited[idx]){
        return 0;
    }
    visited[idx] = true;
    int ans = 1;
    for(auto i : adj[idx]){
        if(!visited[i]){
            ans = ans + get_comp(i);
            visited[i] = true;
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    adj = vector<vector<int>> (n);
    visited = vector<bool>(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0;i<n;i++){
        if(visited[i] == false){
            components.push_back(get_comp(i));
        }
    }
    for(auto i : components){
        cout<<i<<" ";
    }
    cout<<endl;
    long long ans = 0;
    for(auto i : components){
        ans = ans + i*(n-i);
    }
    cout<<(ans/2)<<endl; // (/2) is to avoid over-Counting 
    return 0;
}
/*
    Question:
        There are N friends numbered from 0 to N-1.Ypu have to chose 2 person such that they are not related to each other.
        You are given information in the form of M pairs(X,Y) i.e there is an link between friend X and Y.
        Find out the number of ways in which 2 persons from different groups can be chosen.

    Idea:
        Find the components and their sizes.
        At i'th Component, chose one person from it and other person from the rest of the groups. 
*/