#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    string str;
    cin>>str;
    sort(str.begin(),str.end(), greater<int>());
    cout<<str<<endl;
    int x = stoi(str);
    cout<<x<<endl;
    return 0;
}