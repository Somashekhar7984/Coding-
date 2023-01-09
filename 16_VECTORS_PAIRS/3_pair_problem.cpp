#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

bool Compare(pair<int,int> p1,pair<int,int> p2){
    return(p1.first < p2.first);

}

int main(){
    int arr[] = {10,16,7,14,5,3,2,9};
    vector<pair<int,int>> V;
    for(int i = 0;i<(sizeof(arr)/sizeof(int));i++){
        /*

        pair<int,int>p;
        p.first = arr[i]; // first stores the element
        p.second = i;// second stores the index of the element
        V.push_back(p);

        */
       V.push_back(make_pair(arr[i],i)); // make_pair(n,m) this function makes a pair with n as first element 
                                         // m as second element

    }

    sort(V.begin(),V.end(), Compare);

    for(int i = 0;i<V.size();i++){
        arr[V[i].second] = i;
    }

    for(int i = 0;i<V.size();i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}