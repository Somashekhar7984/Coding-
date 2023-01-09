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

int main(){
    int n;
    cin>>n;
    vector<vector<int>> V;
    for(int i = 0;i<n;i++){
        int start;
        int end;
        cin>>start>>end;
        V.push_back({start,end});
    }

    sort(V.begin(),V.end(), [&] (vector<int> &a,vector<int> &b){
        return a[1] < b[1];     // a[1] ==> represents ending time of 'a'
                                // b[1] ==> represents ending time of 'b'
    });

    int take = 1;
    int end = V[0][1];
    for(int i = 1;i<n;i++){
        if(V[i][0] >= end){
            take++;
            end = V[i][1];
        }
    }
    cout<<"The Maximam number of activities that can be done : "<<take<<endl;

    return 0;
}