#include "bits/stdc++.h"
using namespace std;

/* Dynamic Programming is an algorithmic approach to solve some complex problems easily and save time and number of comparisons by storing the results of past computations. The basic idea of dynamic programming is to store the results of previous calculation and reuse it in future instead of recalculating them.
for ex if we want to calculate 5th no in fibonacci sequence then we need fibo(4) + fibo(3) and fibo(4) = fibo(3)+fibo(2) so we need to calculate fibo(3) twice. If we store the value of fibo(3) somewhere then we can avoid unecessary calls.
Time complexity of normal recursive fibonacci function is exponential. */

// using memoization
vector <int> memo (10000, -1);

int fibo (int n) {
    if (memo[n] == -1) {
        int res;
        if (n==0 || n==1) 
            res = n;
        else 
            res = fibo(n-1) + fibo(n-2);
        memo[n] = res;
    }
    return memo[n];
}

// tabulation
int fib(int n) 
{ 
  int f[n+1];   
  int i; 
  
  f[0] = 0; 
  f[1] = 1; 
  
  for (i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2]; 
  
  return f[n]; 
} 

// longest common subsequence
// LCA of "AGGTAB" and "GXTXAYB"  is "GTAB"
// start from end, if both characters are same, call recursively for remaining string by reducing length by 1 for both strings. Else we reduce length of only one string at a time to see if prev character matches with the curr char of the string.

int lcs (string s1, string s2, int n, int m) {
    if (!n || !m)
        return 0;
    
    if (s1[n-1] == s2[m-1]) {
        return 1 + lcs(s1, s2, n-1, m-1);
    } else {
        return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
    }
}

// dp memoization based solution

vector <vector <int>> memo_lca (1000, vector <int>(1000, -1));

int lcs_dp (string s1, string s2, int n, int m) {
    if (memo_lca[n][m] != -1)
        return memo_lca[n][m];
    
    if (!n || !m)
        memo_lca[n][m] = 0;
    else {
        if (s1[n-1] == s2[m-1]) {
            memo_lca[n][m] =  1 + lcs_dp(s1, s2, n-1, m-1);
        } else {
            memo_lca[n][m] = max(lcs_dp(s1, s2, n-1, m), lcs_dp(s1, s2, n, m-1));
        }
    }

    return memo_lca[n][m];

}

int lcs (string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
        
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// coin change count combinations
// given a sum and a coins array, find the no of ways in which given coins can be arranged to get required sum (infinite supply of coins)
// For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4

int coinChangeRec (int coins[], int n, int sum) {
    if (sum == 0)   return 1;
    if (n == 0)    return 0;

    int res = coinChangeRec(coins, n-1, sum);
    if (coins[n-1] <= sum)
        // not reducing the count of coins because we have infinite supply
        res += coinChangeRec(coins, n-1, sum-coins[n-1]);

    return res;
}

int coinChangeTabu (int coins[], int n, int sum) {
    vector <vector <int>> dp (sum+1, vector <int> (n+1));

    for (int i=0; i<=n; i++)
        dp[0][i] = 1;

    for (int i=0; i<=sum; i++)
        dp[i][0] = 0;

    for (int i=1; i<=sum; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = dp[i][j-1];
            if (coins[j-1] <= i)
                dp[i][j] += dp[i-coins[j-1]][j];
        }
    }
}
// won't work if rows and columns are swapped. Why?
// O(n*sum) both time and space

// edit distance problem
/* Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  
Insert
Remove
Replace
All of the above operations are of equal cost.  */

int editDistRec (string s1, string s2, int n, int m) {
    if (s1[n-1] == s2[m-1])
        return editDistRec(s1, s2, n-1, m-1);
    else 
        // considering all operations: insertion deletetion replacing
        return 1 + min(editDistRec(s1, s2, n, m-1), editDistRec(s1, s2, n-1, m), editDistRec(s1, s2, n-1, m-1));
}


int main () {
    cout << fibo(5) << endl;
}
