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
             English / hindi           DS & Algo       
                    \               /           \
                        coding language          Placement
                    /               \           /
             Internet                Interview Prep

    Topological Sort :
        Englist/hindi --> Internet --> Coding --> DSA --> Interview Prep --> Placement

        Ordering the sequence of events --> Topological Order

    Topological Sort:
        A topological Ordering is an ordering of the nodes in a directed graph where for each from node A to node B
        node A appears before node B in the ordering

    Topological ordering is NOT unique.

    Not Every Graph has a Topological sort. (Whenever there is a cycle in a graph)
    Only Directed Acyclic Graph (DAG) have a valid Topological Sort.

    Sample Test Case && intution:
        The Sort starts from the nodes where the nodes have no incoming edges
            Topological Sort : E F G D B C A

    In-degree:
        The number of inward directed edges on vertex in a directed graph.

*/
/*
    Algorithm:
        While(all nodes are not visited)
            Nodes with zero indegree can be added to the output array.
            All the nodes which are adjacent to terminal nodes, gets their in-degree subtracted. 
*/
/*
    Pseudo Code:
        map<int,int>in_deg;

        for(edge it : edges){
            adj_list[it[1]].push_back(it[0]);
            in_deg[it[0]]++;
        }

        queue<int> pq;
        for(int i = 0;i<n;i++){
            if(in_deg[i] == 0){
                pq.push(i);
            }
        }

        count = 0;
        while(queue is not empty){
            count++;
            int x = pq.front();     // Store the x to output array to get the answer 
            pq.pop();

            for(node it : adj_list[x]){
                in_deg[it]--;
                if(in_deg[it] == 0){
                    pq.push(it);
                }
            }
        }
*/
int main(){
    int n,m;
    cin>>n>>m;  // n = No of vertices
                // m = No of edges
    int count = 0;
    map<int,int> in_deg;
    vector<vector<int>> adj_list(n);
    for(int i = 0;i<m;i++){
        int u,v;    // {u,v} is an edge pointing from 'u' to 'v'
        // u-->v
        cin>>u>>v;
        adj_list[u].push_back(v);
        in_deg[v]++;
    }

    queue<int> pq;
    for(int i = 0;i<n;i++){
        if(in_deg[i] == 0){
            pq.push(i);
        }
    }

    vector<int> ans;
    while(!pq.empty()){
        count++;

        int x = pq.front();
        pq.pop();

        ans.push_back(x);
        vector<int> :: iterator it;
        for(it = adj_list[x].begin();it != adj_list[x].end();it++){
            in_deg[*it]--;
            if(in_deg[*it] == 0){
                pq.push(*it);
            }
        }
    }
    // If ans.size() != n then there is no topological sort (It has a cyclic in it)
    // Hence this can be used for identification of the cycle(DETECTION OF CYCYLE) in a graph 
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}