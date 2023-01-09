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
    LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
    Given a string s, find the length of the longest substring without repeating characters.

    Input:
        abcabcbb
    Output:
        3
    Explanation:
        The answer is "abc", with the length of 3.

    IDEA:
        - while iterating mark the position of each character
        - At i'th character, check the previous occurence and decide the start of the substring accordingly.
*/
int main(){
    map<char,int> mp;
    // Here the map stores the index of the characters in the string
    // Whenever the second occurence comes the we update the start to the previous position
    // Then the update the position in the map with latest new position. 
    int start = 0;
    string str = "pwwkew";
    int ans = 0;
    for(int i = 0;i<str.length();i++){
        if(mp[str[i]]){
            start = mp[str[i]];
        }
        mp[str[i]] = i;
        ans = max(ans,i-start);
    }
    cout<<ans<<endl;
    return 0;
}