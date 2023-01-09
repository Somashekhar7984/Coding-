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
// Adjacency List
vector<int> adj[N];

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

    // For BFS we use queue
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<endl;

        vector<int> :: iterator it;
        for(it = adj[node].begin();it != adj[node].end();it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}
/*
7 7                                 
1 2                                 
1 3                                 
2 4                                 
2 5                                 
2 6
2 7
3 7
*/