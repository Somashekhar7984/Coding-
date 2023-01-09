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
#include<cstring>
using namespace std;
/*
    Matrix Chain Multiplication:
        Problem : We are given 'n' matrices , we hvae to multiply them in such a way that total no of operations 
                    are minimum.
        
        Example : A(1x2) , B(2x3) , C(3x4)

        Since we know multiplication of matrices is associative, hence
            A(BC) = (AB)C

        Operations A(BC) : 
            A (1x2)  ( B(2x3) C(3x4) )
                        2x3x4 --> Operations
                          |
                          v
                        BC(2x4) matrix
                A(1x2)
                    1x2x4 --> Operations
                      |
                      v
                    1 x 4
        Total Operations = 1x2x4 + 2x3x4 = 8 + 24 = 32

        Operations (AB)C :
            ( A(1x2) B(2x3) ) C(3x4)
                1x2x3 --> Operations
                  |
                  v
                 1x3    C(3x4)
                    1x3x4 --> Operations
                      |
                      v
                    1x4
        Total Operations = 1x2x3 + 1x3x4 = 6 + 12 = 18

        Let us take 4 matrices A , B , C , D
       We can see that answer of ABCD depends on
                    (A)(BCD)
                    (AB)(CD)
                    (ABC)(D)

        Whichever from (i),(ii) or (iii) gives minimum Operations , that is the answer.

        So we can write its recurrence as ...
        f(A,B,C,D) = min[f(A | B C D) , f(A B | C D) , f(A B C | D)];

        Since it has recurrence relation , therefore it follows optimal substructure property.

        Input Format:
        Dimensions of matrices will be given in the form of array

        Example : a[] = {10 , 20 , 30 , 20 , 30}

            i'th matrix = a[i-1]xa[i];

            M1 = a[0] x a[1] = 10 x 20;
            M2 = a[1] x a[2] = 20 x 30
            M3 = a[2] x a[3] = 30 x 20;
            M4 = a[3] x a[4] = 20 x 30;

        Therefore Dimension of matrix is multiplication from 
            Mi to Mj ----> a[i-1] x a[j]

        Example:
          M1.M2.M3 = a[0] x a[3] = 10 x 20

          recurrence relation becomes:
            f(M1,M2,....Mn) = min(f(M1,M2...Mk) + f(M (k+1) ....Mn)) + a[0] x a[K] x a[N];
                  where 1 < K < N-1    


*/
const int N = 102,MOD = 1e9+7;
int a[N];
int dp[N][N];
/*
  Memosise method ==> Recursive Method

int mcm(int i,int j){
  if(i == j){
    return 0;
  }
  if(dp[i][j] != -1){
    return dp[i][j];
  }
  dp[i][j] = MOD;
  for(int k = i;k<j;k++){
    dp[i][j] = min(dp[i][j],mcm(i,k) + mcm(k+1,j) + a[i-1]*a[k]*a[j]);
  }

  return dp[i][j];

}
*/
int main(){
  int n;
  cin>>n;
  //memset(dp,-1,sizeof(dp));
  for(int i = 0;i<n;i++){
    cin>>a[i];
  }
  for(int i = 1;i<n;i++){
    dp[i][i] = 0;
  }


  // Tabulation Method
  for(int l = 2;l<n;l++){
    for(int i = 1;i<n-l+1;i++){
      int j = i + l -1;
      dp[i][j] = MOD;
      for(int k = i;k<j;k++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j]);
      }
    }
  }
  cout<<dp[1][n-1]<<endl;
  //cout<<mcm(1,n-1)<<endl;
  return 0;
}