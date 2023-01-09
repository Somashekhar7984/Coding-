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
// Representation of Graphs
int main(){
    int n,m;    // n --> no of vertices
                // m --> no of edges
    cin>>n>>m;

                                        // vector<vector<int>> adjaceny_m(n+1,vector<int>(n+1,0));

                                        // for(int i = 0;i<m;i++){
                                        //     int x,y;
                                        //     cin>>x>>y;
                                        //     adjaceny_m[x][y] = 1;
                                        //     adjaceny_m[y][x] = 1;
                                        // }

                                        // cout<<"The adjacency matrix of the above graph is given by : "<<endl;
                                        // for(int i = 1;i<n+1;i++){
                                        //     for(int j = 1;j<n+1;j++){
                                        //         cout<<adjaceny_m[i][j]<<" ";
                                        //     }
                                        //     cout<<endl;
                                        // }
                                        // cout<<endl<<endl;
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
    int N = 1e5+2;
    vector<int> adj_list[N];
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    cout<<"The adjacency list of the given graph is : "<<endl;
    for(int i = 1;i<n+1;i++){
        cout<<i<<" : ";
        vector<int> :: iterator it;
        for(it = adj_list[i].begin() ; it != adj_list[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }    
    return 0;
}