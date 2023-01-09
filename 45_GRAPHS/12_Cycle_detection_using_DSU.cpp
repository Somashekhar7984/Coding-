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
/*
    Pseudo Code:
        for (all edges(u,v) in edges)
            x = find_set(u)
            y = find_set(v)
            if(x == y)
                // Same set cycle is found
                return true;
            Union(x,y)
        return false;
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
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    bool cycle = false;
    for(auto i : edges){
        int u = i[0];
        int v = i[1];

        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            cycle = true;
        }
        else{
            union_set(u,v);
        }
    }
    if(cycle){
        cout<<"The Cycle is found"<<endl;
    }
    else{
        cout<<"The Cycle is not found"<<endl;
    }
    return 0;
}