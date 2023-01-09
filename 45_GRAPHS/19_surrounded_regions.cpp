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
//  Surrounded Region
/*
    Given a 2D board containing 'X' and 'O'(The letter O),capture all regions surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
/*
    Idea:
    1.  Traverse the 'O' components around the edges of the grid and change it to '*'
    2.  The remaining 'O' components will be surrounded regions that can be captured.
    3.  Change the '*' back to 'O'.

    Sample TestCase:
    X X X X
    X O O X
    X X O X
    X O X X

    Output:
        X X X X
        X X X X
        X X X X
        X O X X
*/
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>A[i][j];
        }
    }

    cout<<endl;
    cout<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if((i == 0) || (i == n-1) || (j == 0) || (j = m-1)){
                if(A[i][j] == 'O')
                A[i][j] = '*';
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}