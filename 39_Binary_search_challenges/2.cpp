#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
    Problem:
        Allocate Minimum Pages:
            n - number of pages in n different books [ascending order]
            m - no of students

        All the books have to be divided among m students, Consecutively.
        Allocate the pages in such way that maximum pages allocated to a student is minimum

    Example:
        Pages = [12,34,67,90]
        students = 2 (m)

            Possible Allocations:
                [12] , [34,67,90] --> Maximum no of pages allocated to a single student == 191 (34+67+90)
                [12,34] , [67,90] --> Maximum no of pages allocated to a single student == 157 (67,90)
                [12,34,67] , [90] --> Maximum no of pages allocated to a single student == 113 (13+34+67)

            out of these minimum of  (Maximum no of pages allocated to a single student) = 113
                --> Parition should be after 67

            So,
                Student 1 = {12,34,90}
                Student 2 = {90}

    Strategy:
        Apply binary search for minimum & maximum possible values of 'max' pages.
        Check the feasibility of this chosen value.

        Feasibility:
            Assign Pages to each student in a sequential manner, while the current number of allocate pages don't 
            exceed the value set by binary search.

            if during allocation the number of students don't exceed the limit of 'm',then the solution is
            feasible.
            else it isn't.

*/

bool is_feasible(int arr[],int n,int m, int min){

    int students_required = 1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] > min){
            return false;
        }
        if(sum + arr[i] > min){
            students_required++;
            sum = arr[i];
            if(students_required > m){
                return false;
            }
        }
        else{
            sum = sum + arr[i];
        }
    }
    return true;
}

int Allocate_minimum_pages(int arr[],int n,int m){
    // n ==> No of Books
    // m ==> No of students

    int sum = 0;
    if(n<m){    // No of Books < No of students ==> then we can't allocate the Books to all students
        return -1;  // NO apporapiate
    }

    for(int i = 0;i<n;i++){
        sum = sum + arr[i];
    }
    int start = 0;
    int end = sum;
    int ans = INT_MAX;

    while(start <= end){
        int mid = (start + end)/2;
        if(is_feasible(arr,n,m,mid)){
            ans = min(ans,mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {12,34,67,90};
    int n = 4;
    int m = 2;
    cout<<"The minimum no of pages : "<<Allocate_minimum_pages(arr,n,m)<<endl;
    return 0;
}