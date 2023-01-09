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
    Properties of Dynamic Programming:
        1. Optimal Substructure                             2. OverLapping SubProblem
            ->If we can write a recurrence relation             ->If Our Subproblems repeat, then a problem
                ,then a problem is said to have Optimal             is said to have a Overlapping SubProblem
                 Substructure

Ways to handle Overlapping Sub Problem:
    1. Memoization (Top - Down): A LookUp table is checked before computation of any state. Recursion is involved.
    2. Tabluation (Bottom - Up): Solution is bulit from base. It is an iterative Process 


    Memoization:
        int fib[200] = {-1};

        int Compute_fib(int n){
            if(n == 0 || n == 1){
                return 1;
            }
            if(fib[n] != -1){
                return fib[n];
            }
            int res = fib[n-1] + fib[n-2];
            fib[n] = res;   // Memoization Part

            return res;
        }


    Tabulation:
        int n;
        cin>>n;

        vector<int> fib(n+1);
        fib[0] = 0;
        fib[1] = 1;

        for(int i = 2;i<=n;i++){            }
            fib[i] = fib[i-1] + fib[i-2];   } Tabulation Part
        }                                   }

        cout<< fib[n] << endl;
*/
/*
    Key Points:
        Minimisation and maximization problems are generally solved with dp where we are exhaustive solution
        (Sometimes with binary search on answer)

        "Find the number of ways" is also a very popular type of problems.

        Wherever we can form recurrence relation or given in question can be solved using DP.
        (Sometimes with Matrix Exponentation).
*/
int main(){
    
    return 0;
}