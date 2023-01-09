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
    Problem:
        Write a rogram to solve a sudoku puzzle by filling the empty cells,
        A sudoku solver must satisfy all of the following rules:
            Each of the digits 1-9 must occur exactly once in each row          
            Each of the digits 1-9 must occur exactly once in each column
            Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid
        The '.' character indicates empty cells
*/
/*
    Recursion?  OR   Math?
*/
/*
    Pseudo Code:
        Start from (0,0) you want reach (8,8)
        Try out all valid Combinations
        ans = false, Currently at (x,y)
        if
            ans = already filled move to next block
        else
            for(number = 1 to 9)
                if you can place number at (x,y)
                    ans = ans or place nuber at (x,y) and move to next block
*/

void Helper(int r,int c,vector<vector<char>> &V, map<pair<int,int>,map<int,int>> &mp,
                        vector<map<int,int>> row,vector<map<int,int>> col){

        if(r == 9){                     // End of the Sudoku
            for(auto it : V){
                for(auto i : it){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return;
        }

        if(c == 9){                     // This Means Row is Completed and we move to next row
            Helper(r+1,0,V,mp,row,col);
            return;
        }

        if(V[r][c] != '.'){             // If The position is not empty we move further
            Helper(r,c+1,V,mp,row,col);
            return;
        }

        for(int i = 1;i<=9;i++){
            int rw = r/3;
            int cl = c/3;
            if(!mp[{rw,cl}][i] && !row[r][i] && !col[c][i]){

                mp[{rw,cl}][i] = 1;
                row[r][i] = 1;
                col[c][i] = 1;

                V[r][c] = i + '0';

                Helper(r,c+1,V,mp,row,col);

                mp[{rw,cl}][i] = 0;
                row[r][i] = 0;
                col[c][i] = 0;
                V[r][c] = '.';

            }
        }



}

void Solve_Sudoku(vector<vector<char>> &V){
    map<pair<int,int>,map<int,int>> mp;         // For 3x3 Grid
    vector<map<int,int>> row(9);                // For Row
    vector<map<int,int>> col(9);                // For Column
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(V[i][j] != '.'){
                mp[ {i/3,j/3} ][V[i][j] - '0'] = 1;
                row[i][V[i][j] - '0'] = 1;
                col[j][V[i][j] - '0'] = 1;
            }
        }
    }
    Helper(0,0,V,mp,row,col);
}
int main(){
    vector<vector<char>> sudoku = {
        {'5' , '3' , '.' , '.' , '7' , '.' , '.' , '.' , '.'},      // 1
        {'6' , '.' , '.' , '1' , '9' , '5' , '.' , '.' , '.'},      // 2
        {'.' , '9' , '8' , '.' , '.' , '.' , '.' , '6' , '.'},      // 3
        {'8' , '.' , '.' , '.' , '6' , '.' , '.' , '.' , '3'},      // 4
        {'4' , '.' , '.' , '8' , '.' , '3' , '.' , '.' , '1'},      // 5
        {'7' , '.' , '.' , '.' , '2' , '.' , '.' , '.' , '6'},      // 6
        {'.' , '6' , '.' , '.' , '.' , '.' , '2' , '8' , '.'},      // 7
        {'.' , '.' , '.' , '4' , '1' , '9' , '.' , '.' , '5'},      // 8
        {'.' , '.' , '.' , '.' , '8' , '.' , '.' , '7' , '9'},      // 9
    };
    Solve_Sudoku(sudoku);
    return 0;
}