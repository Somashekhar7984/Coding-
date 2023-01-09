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
#include<set>
using namespace std;
/*
    Idea:
        Select an arbitrary vertex s to start tree form.
            while(there are still non-tree vertices)
                Select the edge of minimum weight between a tree and non-tree vertex.
                Add the selected edge and vertex to the tree.

    Sample TestCase:
        4 5
        0 1 10
        1 2 15
        0 2 5
        3 1 2
        3 2 40
*/
int n,m;
const int N = 1e5+3;
vector<vector<int>> g[N];
int cost = 0;

const int INF = 1e9;
vector<int> dist(N),parent(N);
vector<bool> visited(N);


void prim_MST(int source){
    for(int i = 0;i<n;i++){
        dist[i] = INF;
    }

    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0,source});
    // {wt,vertex}
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost = cost + w;
        for(auto it : g[x[1]]){
            if(visited[it[0]]){
                continue;
            }
            if(dist[it[0]] > it[1] ){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }   

    }
    cout<<cost<<endl;

}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v,w;
        // vertex 1,vertex 2,weight
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    prim_MST(0);
    return 0;
}