#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // Matrix Transpose
    //  ---- my code ----
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            swap(&arr[i][j],&arr[j][i]);
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}