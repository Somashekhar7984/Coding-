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
// Dis-Joint Set Union (Union - Find)
/*
    Leading Element:
        Element which can be regarded as the leader element for that set
            eg: P = {1,2,3,4}
                    Leader = 2 (Leader can be any number chosen)
                        Parent[1] = parent[2] = parent[3] = parent[4] = 2 = used to identify the set.
        
    Basic Implementation of DSU
        Union (1,2) =====>  1 <--- 2   (making 1 as the leader)
        Union (3,4) =====>  3 <--- 4   (making 3 as the leader)

        Now Union of (2,4) ==> (This results the Union of the leader of 2 and 4) --> i.e. (1,3)

               1
             /  \
            2     3 ---- 4  (Now 1 is the new leader of the new group).
*/
/*
    Applications:
    1.  MST --> Minimum Spanning Tree
    2.  Connected Components in a Graph
    3.  Cycle Detection and Many more.
*/
int main(){
    
    return 0;
}