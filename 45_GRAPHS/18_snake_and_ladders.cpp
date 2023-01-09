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
    The Game of snake and ladders.
    You are at square 1 and have to reach square 100.you have complete control over the die and can get any number
    from 1-6.
    For given ladders and snakes,find the minimum steps to reach.

    sample testcase:
        2       // No of ladders
        3 90    // Jumps from 3 to 90 because of ladder
        56 76
        3       // No of snakes
        99 10   // Snakes take down the player to low position
        30 20
        20 5

    Output:
        3

        Explanation:
            1 --> (3-->90) --> 95 --> 100
*/
/*
    Idea:
        1. BFS!
        2. Push 1 into the queue
            for all possiblities in the dice:
                Check if the next position is ladder,snake or empty.
                Mark the sqaure visited and push into queue.
        3. Stop traversal, when you reached 100
*/
int main(){
    int ladders,snakes;
    cin>>ladders;
    map<int,int> lad;
    map<int,int> snak;
    for(int i = 0;i<ladders;i++){
        int u,v;
        cin>>u>>v;
        lad[u] = v;
    }
    cin>>snakes;
    for(int i = 0;i<snakes;i++){
        int u,v;
        cin>>u>>v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> visited(101,0);
    visited[1] = 1;
    while(!q.empty() && !found){
        int sz = q.size();
                while(sz--){
                    int t = q.front();;
                    q.pop();
                    for(int die = 1;die<=6;die++){
                        if(die + t == 100){
                            found = true;
                        }
                        // If there is ladders in the way
                        else if(t+die <= 100 && lad[t + die] && !visited[lad[t + die]]){
                            visited[lad[t + die]] = true;
                            if(lad[t + die] == 100){
                                found = true;
                            }
                            q.push(lad[t + die]);
                        } 
                        // if there is snak in the way
                        else if(t + die <= 100 && snak[t+die] && !visited[snak[t+die]]){
                            visited[snak[t + die]] = true;
                            if(snak[t+die] == 100){
                                found = true;
                            }
                            q.push(snak[t+die]);
                        }
                        // Empty position
                        else if(t + die <= 100 && !snak[t+die] && !lad[t+die] && !visited[t+die]){
                            visited[t+die] = true;
                            q.push(t+die);
                        }
                    }
                }
        moves++;
    }
    if(found)
    cout<<moves<<endl;
    else{
        cout<<-1<<endl;
    }
    return 0;
}