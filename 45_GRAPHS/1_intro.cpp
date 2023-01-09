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
    Real life example:
        User Connections in facebook

    Components of a Graph:
        Nodes --> These are the states or vertex. For instance,users in case of facebook
        Edges --> Links between states in graph. For instance, Connections between users

            undirected edges --> Two way edge   (<--->)
            Directed edges   --> One way edge   (---->)

    Adjacency Matrix                                    Adjacency List
      2D - array                                        Array of list,where each a[i] is a list of nodes x that 
        a[i][j] = 1 only if there is an                     are reacheable from i
                    edge between i and j
        else
            a[i][j] = 0

        0 0 0 1                                                 a    b-->d-->e
        0 0 0 1                                                 b    c
        0 0 0 1                                                 c    d
        1 1 1 0                                                 d    a
                                                                e

*/
/*
    Depth First Search
            Parts
            1.  Pre-order
                    First time when call comes on the node
            2.  In-order
                    When the call works inside the subtree (in DFS Tree) of that node
            3.  Post-order
                    After working on the subtree,call comes back on the node. After this,call won't come on the same node.
        Implemented using Stacks

    Breadth First Search
        Implemented using queues    
*/
/*
    Different Properties of Components of Graph
        1.  Weighted nodes - Values are associated with nodes
        2.  Weighted edges - Values are associated with edges
*/
int main(){
    
    return 0;
}