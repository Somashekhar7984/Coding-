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
    FLOYD WARSHALL ALGORITHM:
        To find all pair shortest paths
        i.e. for every u,v in graph G,find the shortest path(least weight) from u to v.
*/

/*
    Pseudo Code:
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
        }
*/
const int inf = 1e9;

int main(){
    vector<vector<int>> graph = {   {0,5,inf,10},
                                    {inf,0,3,inf},
                                    {inf,inf,0,1},
                                    {inf,inf,inf,0},
                                };
    int n = graph.size();
    vector<vector<int>> dist = graph;
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 0;i<dist.size();i++){
        cout<<"The vertex "<<i<<" : ";
        for(int j = 0;j<n;j++){
            if(dist[i][j] == inf){
                cout<<-1<<" ";
                continue;
            }
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}