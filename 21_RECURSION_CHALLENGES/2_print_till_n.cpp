#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

/*

print_decreasing order == 9 8 7 6 5 4 3 2 1
printf_increasing order == 1 2 3 4 5 6 7 8 9
*/
void print_d(int n){
    if(n == 1){
        cout<<n;
        return;
    }
    printf("%d ",n);
    print_d(n-1);
}
void print_a(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    print_a(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cin>>n;
    print_d(n);
    cout<<endl;
    print_a(n);
    return 0;
}