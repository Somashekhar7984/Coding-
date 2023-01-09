#include<bits/stdc++.h>
using namespace std;
//  MINIMUM SPANNING TREE
/*
    Given an un-directed and connected graph G(V,E),a spanning tree of the graph G is a tree that spans G
    (that is , it includes every vertex of G)and is a subgraph of G(Evry edge in the tree belongs to G).

    Cost of the Spanning Tree
        The Cost of the spanning tree is the sum of the weights of all the edges in the tree.
        
        There can be many spanning trees.
    Minimum Spanning Tree:
        Minimum Spanning Tree is the spanning tree where the cost is minimum among all the spanning trees.

        There can also be many minimum spanning trees.
*/
/*
    Pseudo-code:
        1. Sort the edges in increasing Order of their weights.
        2. Iterate in the sorted edges,
                if inclusion of the i'th edge leads to cycle,then skip this edge.
                else
                    Include the edge in the MST.

    Sorting them by weights:
        {w,u,v} --> w = weight of the edge
                --> u = starting vertex of the edge
                --> v = ending vertex of the edge
            
            {1,5,8} , {1,8,7} , {2,4,3} , {5,1,2} , {5,3,5} , {6,2,3} , {7,6,7} , {9,1,4} , {10,5,6}
    
    Complexity Analysis:
        Time Complexity : O(E log V)
        Space Complexity : O(E + V)
        
*/
const int N = 1e5+2;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int n){
    parent[n] = n;
    sz[n] = 1;  // Making the size of set == 1
}
int find_set(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n] = find_set(parent[n]);
}
void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]){
            swap(a,b);
        }
        parent[b] = a;      // Attaching the small tree to larger tree
        sz[a] = sz[a] + sz[b];
    }
}
int main(){
    for(int i = 0;i<N;i++){
        make_set(i);
    }

    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());

    int cost = 0;
    for(auto i : edges){
        int u = i[1];
        int v = i[2];
        int w = i[0];

        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            continue;
        }
        else{
            cout<<u<<" "<<v<<endl;
            cost = cost + w;
            union_set(u,v);
        }
    }
    cout<<"The Cost of the tree : "<<cost<<endl;
    return 0;
}
/*
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1
*/