#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;
// See this problem after sets
//                      sliding window maximum
/*
        consider an array  ===  [ 1, 3, -1, -3, 5, 3, 6, 7 ]
                K = 3  (size of window)
        1st window = first 3 elements = [1, 3, -1] ===> Maximum number out of these elements is ===> 3
        2nd window = 3 elements from position 2 = [3, -1, -3] ===> Maximum number out of these elements is ===> 3
        3rd window = 3 elements from position 3 = [-1, -3, 5] ===> Maximum number out of these elements is ===> 5
        4th window = 3 elements from position 4 = [-3, 5, 3 ] ===> Maximum number out of these elements is ===> 5
        5th window = 3 elements from position 5 = [ 5, 3, 6 ] ===> Maximum number out of these elements is ===> 6
        6th window = 3 elements from position 6 = [ 3, 6, 7 ] ===> Maximum number out of these elements is ===> 7

    Now the function returns an array = [ 3, 3, 5, 5, 6, 7 ] ==> output    
 
*/
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

                    // // O(n logn)
                    // multiset<int,greater<int>> s;
                    // vector<int> ans;
                    // for(int i = 0;i<k;i++){
                    //     s.insert(a[i]);
                    // }

                    // ans.push_back(*s.begin());

                    // for(int i = k;i<n;i++){
                    //     s.erase(s.lower_bound(a[i-k]));     // delete the first occurence of the a[i-k]
                    //     s.insert(a[i]);
                    //     ans.push_back(*s.begin());
                    // }
                    // for(int i = 0;i<ans.size();i++){
                    //     cout<<ans[i]<<" ";
                    // }




    //O(n) using deque

    deque<int> q;       // Here the deque is used to store indices of the elements
    vector<int> ans;
    for(int i = 0;i<k;i++){
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);
    for(int i = k;i<n;i++){
        if(q.front() == i-k){       // When the element in the deque will go out of the window
            q.pop_front();          // Then we will remove that element from the deque
        }
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}