#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int given_sum;
    cin>>given_sum;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int i = 0,j = 0,start = -1,end = -1 ,sum = 0;
    while(j<n && (sum + arr[j] <=given_sum)){
        sum = sum + arr[j];
        j++;
    }
    if(sum == given_sum){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }


    while(j<n){
        sum = sum + arr[j];
        while(sum>given_sum){
            sum = sum - arr[i];
            i++;
        }

        if(sum == given_sum){
            start = i+1;
            end = j+1;
            break;
        }
        j++;
    }
    cout<<start<<" "<<end<<endl;

    return 0;
}


/*

int sum(int arr[],int start,int end){
    int total = 0;
    for(int i = start;i<end;i++){
        total = total + arr[i];
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int given_sum;
    cin>>given_sum;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(sum(arr,i,j) == given_sum){
                cout<<i+1<<" "<<j<<endl;
                return 0;
            }
        }
    }

    return 0;
}

*/