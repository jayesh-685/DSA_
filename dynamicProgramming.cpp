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

int lca1 (string s1, string s2, int n, int m) {
    if (!n || !m)
        return 0;
    
    if (s1[n-1] == s2[m-1]) {
        return 1 + lca1(s1, s2, n-1, m-1);
    } else {
        return max(lca1(s1, s2, n-1, m), lca1(s1, s2, n, m-1));
    }
}

// dp memoization based solution

vector <vector <int>> memo_lca (1000, vector <int>(1000, -1));

int lca1_dp (string s1, string s2, int n, int m) {
    if (memo_lca[n][m] != -1)
        return memo_lca[n][m];
    
    if (!n || !m)
        memo_lca[n][m] = 0;
    else {
        if (s1[n-1] == s2[m-1]) {
            memo_lca[n][m] =  1 + lca1(s1, s2, n-1, m-1);
        } else {
            memo_lca[n][m] = max(lca1(s1, s2, n-1, m), lca1(s1, s2, n, m-1));
        }
    }

    return memo_lca[n][m];

}

int main () {
    cout << fibo(5) << endl;
}
