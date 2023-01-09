#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cin>>str;
    int freq[26];
    for(int i = 0;i<26;i++){
        freq[i] = 0;
    }
    for(int i = 0;i<str.length();i++){
        freq[str[i] - 'a']++;
    }
    char ans = 'a';
    int maxF = 0;
    for(int i = 0;i<26;i++){
        if(freq[i] > maxF){
            maxF = freq[i];
            ans = 'a' + i;
        }
    }
    cout<<ans<<" "<<maxF<<endl;
    return 0;
}