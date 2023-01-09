#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
// There is some bugg in this code try it afterwards
int main(){
    int n;
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr,n); // This takes space (" ") as input and will not end until we go for a new line
    // same as scanf("%[\n]s",arr);
    arr[n+1] = '\0';
    cin.ignore(); // This works as flush function in C++

    int i = 0;
    int current_length = 0;
    int max_length = 0;
    
    int start = 0;
    int max_start = 0;

    while(i<n){

        if(arr[i] == ' ' || arr[i] == '\0'){
            if(current_length > max_length){
                max_start = start;
                max_length = current_length;
            }
            start = i+1;
            current_length = 0;
        }
        else{
            current_length++;
        }  

        if(arr[i] == '\0'){
            break;
        }   
        i++;
    }
    cout<<arr<<endl;
    cout<<max_length<<endl;

    for(int i = 0;i<max_length;i++){
        cout<<arr[i+max_start];
    }
    cout<<endl;

    return 0;
}