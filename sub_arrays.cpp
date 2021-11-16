#include "bits/stdc++.h"
using namespace std;

void prineSubArrays (int arr[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

int max_sum_sub_arr_m1 (int arr[], int n) {
    // brute force method  // O(n^3)
    int maxSum = INT_MIN;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int currSum = 0;
            for (int k=i; k<=j; k++)
                currSum += arr[k];
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

int max_sum_sub_arr_m2 (int arr[], int n) {
    // slightly more optimised  // O(n^2)
    int cs_arr [n+1];
    cs_arr[0] = 0;
    for (int i=1; i<=n; i++)
        cs_arr[i] = cs_arr[i-1] + arr[i-1];
    int max_sum = INT_MIN;                          
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int currSum = cs_arr[j+1] - cs_arr[i];
            max_sum = max(max_sum, currSum);
        }
    }
    return max_sum;
}

int kadanes_algorithm (int arr[], int n) {
    // very efficient algo to find max sum sub arr
    // O(n)
    // just keep track of the current sum till ith element
    // if it becomes -ve then we won't include that sub array
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i=1; i<n; i++) {
        currSum += arr[i];
        if (currSum < 0)
            currSum = 0;
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
} 

// in case there is wrapping of elements that is you can consider elements both from staring and ending at the same time
// ex - {4 -4 6 -6 10 -11 12}
// here we would consider all elements for sub array except -11
// so we can calculate sum by subtracting sum of non-contributing elements from total sum of array
// we can find the non contributing elements by reversing the sign of each element and then using kadan's algorithm

int max_circular_subarray_sum (int arr[], int n) {

    int nonWrapSum = kadanes_algorithm(arr, n);
    int totalSum = 0;
    for (int i=0; i<n; i++) {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    
    int nonContriSum = kadanes_algorithm(arr, n);
    int wrapSum = totalSum + nonContriSum;  // - - = +
    return max(wrapSum, nonWrapSum);
}


bool pairSum (int arr[], int n, int k) {
    // find 2 elements whose sum is equal to k
    // if found in given array, return true
    // brute force method would be to check all elements using two loops
    // this is one is a bit optimized and is O(n) but requires a sorted array
    int sp = 0, ep = n-1;
    while (sp < ep) {
        if (arr[sp] + arr[ep] == k) {
            cout << sp << " " << ep << endl;
            return true;
        } else if (arr[sp] + arr[ep] > k) {
            ep--;
        } else {
            sp++;
        }
    }
    return false;
}
int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << pairSum(arr, n, k) << endl;

    return 0;
}