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

    return dp[n][sum];
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
        return 1 + min(editDistRec(s1, s2, n, m-1), min(editDistRec(s1, s2, n-1, m), editDistRec(s1, s2, n-1, m-1)));
}

int editDistTab (string s1, string s2, int n, int m) {
    vector <vector <int>> dp (n+1, vector <int> (m+1));

    for (int i=0; i<=m; i++)
        dp[0][i] = i;

    for (int i=0; i<=n; i++)
        dp[i][0] = i;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }

    return dp[n][m];
}
// theta(n*m)

// longest increasing subsequence

int lis (vector <int> arr, int n) {
    vector <int> ans (n);
    ans[0] = 1;

    for (int i=1; i<n; i++) {
        ans[i] = 1;
        for (int j=0; j<i; j++) {
            if (arr[j] <= arr[i]) 
                ans[i] = max(ans[i], ans[j]+1);
        }
    }

    int res = ans[0];
    for (int i=1; i<n; i++)
        res = max(res, ans[i]);

    return res;
}

// maximum cuts
// given a rope of length n and 3 integers a, b and c find the maximum no of cuts so that every piece is of length a, b or c

int maxCutsRec (int n, int a, int b, int c) {

    if (n < 0)    return -1;
    if (n == 0)    return 0;

    int res = max(maxCutsRec(n-a, a, b, c), max(maxCutsRec(n-b, a, b, c), maxCutsRec(n-c, a, b, c)));
    // not adding 1 here because if all 3 calls return -1 then it will return 0 which is wrong

    if (res == -1)
        return res;
    return res+1;
} // O(3^n)

int maxCutsTab (int n, int a, int b, int c) {
    vector <int> dp (n+1);
    dp[0] = 0;

    for (int i=1; i<=n; i++) {
        dp[i] = 0;
        if (i-a >= 0)   dp[i] = max(dp[i], dp[i-a]);
        if (i-b >= 0)   dp[i] = max(dp[i], dp[i-b]);
        if (i-c >= 0)   dp[i] = max(dp[i], dp[i-c]);

        if (dp[i] != -1)
            dp[i]++;
    }

    return dp[n];
} // theta(n)

// minimum coins to make a value
int minCoinsRec (int coins[], int n, int val) {
    int res = INT_MAX;
    for (int i=0; i<n; i++) {
        if (coins[i] <= val) {
            int sub_res = minCoinsRec(coins, n, val-coins[i]);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }

    return res;
}

int minCoinsTab (int coins[], int n, int val) {
    vector <int> dp (val+1);
    dp[0] = 0;

    for (int i=1; i<=val; i++) {
        for (int j=0; j<n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]]; 
                if (sub_res != INT_MAX  && sub_res + 1 < dp[i]) 
                    dp[i] = sub_res + 1;
            }
        }
    }

    return dp[val];
}

// minimum jumps to reach end
/* Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, they cannot move through that element. If the end isn’t reachable, return -1.
Examples: 
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 9 -> 9) */

// start from 0 and call recursively for each element from which last index can be reached
int minJumpsRec (int arr[], int n) {

    if (n == 1)
        return 0; 

    int res = INT_MAX;
    for (int i=0; i<n-1; i++) {
        if (arr[i] >= n-i-1) {
            int sub_res = minJumpsRec(arr, i+1);
            if (sub_res != INT_MAX)
                res = min(sub_res+1, res);
        }
    }

    return res;
}

int minJumpsTab (int arr[], int n) {
    vector <int> dp (n, INT_MAX);
    // dp[i] = minimum jumps to reach index i from 0
    dp[0] = 0;

    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j]+j >= i) {
                if (dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }

    return dp[n-1];
} // Theta(n^2) theta(n)

// 0 1 knapsack
int knapsack01Rec (int wt[], int val[], int n, int W) {

    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] > W)
        return knapsack01Rec(wt, val, n-1, W);
    else 
        return max(knapsack01Rec(wt, val, n-1, W), knapsack01Rec(wt, val, n-1, W-wt[n-1]));
}

int knapsack01Tab (int wt[], int val[], int n, int W) {
    vector <vector <int>> dp (n+1, vector <int> (W+1));
    // dp[i][j] represents max value we can collect with i items and knapsack capacity j

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=W; j++) {
            if (wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
        }
    }

    return dp[n][W];

} // theta(n*W)

// optimal strategy for the game
/* Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.
Note: The opponent is as clever as the user. */
// we can control if the opponent always choses odd coins or even coins... so if we calculate the sum of odd coins and even coins then we can make sure we never loose, if not win by the biggest value.

int optimalStratHelp (int arr[], int i, int j, int sum) {

    // if there are only two elements
    if (i+1 == j)
        return max(arr[i], arr[j]);

    // calculate the sum of opponent then subtract it from total sum to get our sum
    return max(sum - optimalStratHelp(arr, i+1, j, sum-arr[i]), sum - optimalStratHelp(arr, i, j-1, sum-arr[j]));
}

int optimalStrat (int arr[], int n) {
    int sum = 0; 
    for (int i=0; i<n; i++)
        sum += arr[i];
    
    return optimalStratHelp(arr, 0, n-1, sum);
    // opponent is as clever as the user so we get the opponent's optimal value and subtract it from the sum
}

// if we convert the above solution into a tabulation based dp solution then due to the large value of sum we will require a huge amount of aux space so we'll try deriving a solution without needing to calculate sum

// you can pick ith coin or jth coin. If you pick ith coin opponent will choose from (i+1)th coin and jth coin such that you get the minimum value after he picks the coin.

int optimalStratHelp2 (int arr[], int n, int i, int j) {

    if (i+1 == j) 
        return max(arr[i], arr[j]);

    return max((arr[i] + min(optimalStratHelp2(arr, n, i+2, j), optimalStratHelp2(arr, n, i+1, j-1))), (arr[j] + min(optimalStratHelp2(arr, n, i+1, j-1), optimalStratHelp2(arr, n, i, j-2))));
}

int optimalStrat2(int arr[], int n) {
    return optimalStratHelp2(arr, n, 0, n-1);
}

// for tabulation based solution our answer is top right corner and not bottom right becuause we get our answer when i=0 and j=n-1. Also we don't need values corresponding to the diagonal or below it becuase i is always less than j.
int optimalStratTab (int arr[], int n) {
    return 0;
}

/* You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is. */

int eggDropRec (int floors, int eggs) {

    if (floors == 0 || floors == 1)    return floors;
    if (eggs == 1)    return floors;

    int res = INT_MAX;
    for (int i=1; i<=floors; i++) {
        int val = max(eggDropRec(floors-i, eggs), eggDropRec(i-1, eggs-1));
        res = min(res, val);
    }

    return res+1;
}

// no of bsts with n nodes
int bstNkeys (int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        int res = 0;
        for (int j=0; j<i; j++) 
            res += dp[j]*dp[i-j-1];
        dp[i] = res;
    }

    return dp[n];
}

int mcn (vector <int> v) {
    int n = v.size();
    vector <vector <int>> mcn (n-1, vector <int> (n-1));

    for (int g=0; g<mcn.size(); g++) {
        for (int i=0, j=g; j<mcn.size(); i++, j++) {
            if (g == 0) {
                mcn[i][j] == 0; 
            } else if (g == 1) {
                mcn[i][j] = v[i] * v[j] * v[j+1];
            } else {
                int minVal = INT_MAX;
                for (int k=i; k<j; k++) {
                    int lc = mcn[i][k];
                    int rc = mcn[k+1][j];
                    int mc = v[i] * v[k+1] * v[j+1];
                    int total = lc + rc + mc;
                    minVal = min(minVal, total);
                }
                mcn[i][j] = minVal;
            }
        }
    }

    return mcn[0][mcn.size()-1];
}

// maximum sum with no two consecutive 
int main () {
    // cout << fibo(5) << endl;
    // cout << editDistTab("CAT", "CUT", 3, 3);

    // vector <int> arr = {3, 4, 2, 8, 10, 5, 1};
    // cout << lis(arr, 7);

    // int arr[] = {20, 30, 2, 2, 2, 10};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout << optimalStrat2(arr, n);

    // cout << eggDropRec(7, 3);
    // cout << bstNkeys(4);

    vector <int> v = {10, 20, 30, 40, 30};
    cout << mcn(v) << endl;
}
