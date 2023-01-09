#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n,m;
    int given_number;
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter the matrix : "<<endl;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the element to be searched : "<<endl;
    cin>>given_number;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j] == given_number){
                cout<<i+1<<" "<<j+1<<endl;
                cout<<"Element Found"<<endl;
                return 0;
            }
        }
    }
    cout<<"Element Not Found"<<endl;
    return 0;
}   