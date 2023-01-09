#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1); // inserts the element at the end of the vector
    v.push_back(2);
    v.push_back(3);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // 1 2 3
    vector<int>:: iterator it;
    for(it = v.begin();it != v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    // 1 2 3

    for(auto element : v){
        cout<<element<<" ";
    }
    cout<<endl;
    v.pop_back(); // remove the last element in the vector
    // 1 2

    vector<int> v2 (3,50); // (no of elements in the vector , value of the element)
    // The vector v2 will be 50 50 50

    swap(v,v2); // This function is used for swapping the vectors
    // checking the vectors swapped or not
    for(auto element : v){
        cout<<element<<" ";
    }
    cout<<endl;

    for(auto element : v2){
        cout<<element<<" ";
    }
    cout<<endl;

    v.push_back(-1);
    sort(v.begin(),v.end());
    for(auto element : v){
        cout<<element<<" ";
    }
    cout<<endl;

    return 0;
}