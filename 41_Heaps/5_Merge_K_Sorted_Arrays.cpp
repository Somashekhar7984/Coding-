#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*
    You will be given K - Sorted Arrays
        ==> We need to return the merged array of all the given array

    Eg:
        1 ===> 1,4,7
        2 ===> 3,5
        3 ===> 2,6,7

        Final array ==> 1 2 3 4 5 6 7 7

    Brute Force:
        Take Two arrays and merge them, repeat this process until we are left with one array
            (similarly a we did in merge sort for sorted arrays)

    Efficient Solution:
        1 => Create a min heap of pairs.    (pair will be ==> (value, array_number ))
        2 => Insert{first element,array number} of all the sorted arrays into min_heap
        3 => Main Idea:
                    We will pop element from the min heap and store into the answer array.
                    Insert the next element of the sorted array into min_heap
        4 => We also need to Keep track of the indices of the elements 
*/
int main(){
    int k;
    cin>>k;
    vector<vector<int>> V(k);
    for(int i = 0;i<k;i++){
        int size;
        cin>>size;
        V[i] = vector<int>(size);
        for(int j = 0;j<size;j++){
            cin>>V[i][j];
        }
    }
    vector<int> idx(k,0);
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    for(int i = 0;i<k;i++){
        pq.push({V[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> P = pq.top();
        pq.pop();
        
        ans.push_back(P.first);
        if(idx[P.second] + 1 < V[P.second].size()){
            pq.push({V[P.second][idx[P.second] + 1],P.second});
        }
        idx[P.second] = idx[P.second] + 1;
    }

    // Printing the final sorted array
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}