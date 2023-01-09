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
// BELLMAN FORD ALGORITHM
/*
    Problem:
        From a source vertex v,find the shortest distance to all other nodes in the graph.

    Idea:
    1.  initially d[v] = 0 and for all other elements d[] = infinite
    2   in each pass,relax all the edges.
            i.e. for edge (a,b) having weight w,
                d[b] = min(d[b],d[a] + w)
    3.  Assuming no negative edge cycle,since there are n vertices,shortest path can only contain
        'n-1' edges.Therefore, we will get our answer in at most 'n-1' passes.

    Sample Test Case:
        5 8
        1 2 3
        3 2 5
        1 3 2
        3 1 1
        1 4 2
        0 2 4
        4 3 -3
        0 1 -1
        0

    Output:
        0 -1 2 -2 1 

    What makes it better than dijstra
        Negative Edges!!
        --> It will work for negative edges and negative cycles,
        --> It can detect negative cycles as well.    
*/
const int inf = 1e9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;
    cin>>src;
    vector<int> dist(n,inf);
    dist[src] = 0;
    for(int iter = 0;iter<n-1;iter++){
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v],w + dist[u]);
        }
    }
    for(auto i : dist){
        cout<<i<<" ";
    }
    return 0;
}