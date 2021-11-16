#include "bits/stdc++.h"
using namespace std;

void traverse (int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int secondLargest (int arr[], int n) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i=0; i<n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        if (arr[i] < max1 && arr[i] > max2)
            max2 = arr[i];
    }
    return max2;
}

// Theta(1)
void reverseArr (int arr[], int n) {
    for (int i=0; i<n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-i-1]; 
        arr[n-i-1] = temp;
    }
}

int removeDuplicates (int arr[], int n) {
    int size = 1;
    for (int i=1; i<n; i++) {
        if (arr[i] != arr[size-1]) {
            arr[size] = arr[i];
            size++;
        }
    }
    return size;
}

void zeroToLast (int arr[], int n) {
    // whenever you find a non zero element just swap it with the first zero index of which can be found by keeping track of no of non zero elements

    int count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

void leftRotate (int arr[], int n) {
    int temp = arr[0];
    for (int i=1; i<n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}

// left rotate by d
// Theta(nd) solution is to simply call the left rotate by 1 function d times

// solution with time complexity theta(n) but uses theta(d) extra space

/* void leftRotateD (int arr[], int n, int d) {
    int tempArr [d];

    for (int i=0; i<d; i++)
        tempArr[i] = arr[i];
    
    for (int i=d; i<n; i++)
        arr[i-d] = arr[i];

    for (int i=n-d; i<n; i++)
        arr[i] = tempArr[i-n+d];
} */

// uses O(1) extra space

void leftRotateD (int arr[], int n, int d) {
    // reverse the first d elements, then the remaining d and then the complete array
    reverseArr(arr, d);
    reverseArr(arr+d, n-d);
    reverseArr(arr, n);
}

void leaderInArray (int arr[], int n) {
    // if there is no greater element to the right of an element then it is a leader in the array
    vector <int> vec;
    int currLeader = arr[n-1];
    vec.push_back(arr[n-1]);

    for (int i=n-2; i>=0; i--) {
        if (arr[i] > currLeader) {
            vec.push_back(arr[i]);
            currLeader = arr[i];
        }
    }
    reverse(vec.begin(), vec.end());
    for (int v : vec)
        cout << v << " ";
} // Theta(n)

int maxDiff (int arr[], int n) {
    // max value of arr[j] - arr[i] such that j > i

    int ans = INT_MIN;
    int currMax = arr[n-1];

    for (int i=n-2; i>=0; i--) {
        ans = max(ans, currMax-arr[i]);
        currMax = max(currMax, arr[i]);
    }

    return ans;
}  // Theta(n)

void freqOfElements (int arr[], int n) {
    // print frequence of each element in an sorted array along with the element
    int freq = 1;
    int i = 0;

    while (i < n) {
        freq = 1;
        while (i < n && arr[i] == arr[i+1]) {
            freq++;
            i++;
        }
        cout << arr[i] << " " << freq << endl;
        i++;
    }
}

// if you know the price of stock on each day how will you buy and sell to get max profit
int stockBuySell (int arr[], int n) {
    int profit = 0;

    for (int i=1; i<n; i++) 
        if (arr[i] > arr[i-1])
            profit += arr[i]-arr[i-1];
    
    return profit;
}

// max consecutive 1s in a boolean array
int maxCons1s (int arr[], int n) {
    int count = 0;
    int maxCount = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == 0)
            count = 0;
        else {
            count++;
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

// O(n^2)
int maxSumSubArr1 (int arr[], int n) {
    int currSum = 0, maxSum = INT_MIN;

    for (int i=0; i<n; i++) {
        currSum = 0;
        for (int j=i; j<n; j++) {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int maxSumSubArr2 (int arr[], int n) {
    int sumArr [n+1];
    sumArr[0] = 0;
    for (int i=1; i<=n; i++)
        sumArr[i] = sumArr[i-1] + arr[i-1];

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i=0; i<n; i++) {
        currSum = 0;
        for (int j=i; j<n; j++) {
            currSum = sumArr[j+1] - sumArr[i];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

// kadane's algorithm
// for each element we find the max sum of all sub arrays which end with that element 
// which is essentially the max of arr[i]+lastMaxSum and arr[i]

int maxSumSubArr3 (int arr[], int n) {
    int lastMaxSum = arr[0];
    int maxSum = INT_MIN;

    for (int i=1; i<n; i++) {
        lastMaxSum = max(arr[i], lastMaxSum+arr[i]);
        maxSum = max(maxSum, lastMaxSum);
    }

    return maxSum;
}

int evenOddSubArr (int arr[], int n) {
    int count = 1, maxCount = 0;
    int i=0;
    while (i < n-1) {
        while (i<n-1 && abs(arr[i+1]%2) - abs(arr[i]%2)) {
            count++;
            i++;
        }
        maxCount = max(maxCount, count);
        count = 1;
        i++;
    }
    return maxCount;
}

// find the majority element, if any, in the array
// majority element is the one which occurs more than n/2 times
// one approach is to sort the array and then traverse it maintaining max count
// O(nlogn) because of sorting algorithm

// other way is Using Moore’s Voting Algorithm
// if a majority element does exist (say x) then for n x we have n non x which cancel each other and we are left with 1 x proving it is the majority element
// Algorithm: 
// Loop through each element and maintains a count of majority element, and a majority index, maj_index
// If the next element is same then increment the count if the next element is not same then decrement the count.
// if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
// Now again traverse through the array and find the count of majority element found.
// If the count is greater than half the size of the array, print the element
// Else print that there is no majority element

int majorityElement (int arr[], int n) {
    int count = 1;
    int res = 0;

    for (int i=1; i<n; i++) {
        if (arr[i] == arr[res])
            count++;
        else
            count--;

        if (count == 0) {
            count = 1;
            res = i;
        }
    }

    // this part is not required if know that given array has a majority element

    count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == arr[res])
            count++;
    }
    if (count <= n/2)
        return -1;
    return res;
    // this algorithm may not return the first occurance of the majority element
}

void minimumFlips (int arr[], int n) {
    // given a binary array, write the index of elements which need to be flipped so that the array becomes same and no of flips is minimum

    // so the binary array will have elements in groups of 0s and 1s, we just have to find out which group occurs less times
    // if you THINK then the diff in frequency of groups is either 0 or 1
    // also the 2nd group always occurs either 1 less time or equal no of times so we we have to always flip the second group

    /* int flip;
    if (arr[0] == 0)
        flip = 1;
    else
        flip = 0;

    int i=0, j=0;
    while (i<n && j<n) {
        if (arr[i] == flip) {
            j=i;
            while (j<n && arr[j] == flip)
                j++;
            cout << "flip " << i << " to " << j-1 << endl;
            i = j;
        } else {
            i++;
        }
    } */

    // can also do this way, we print only when there is change and compare it with the first element

    for (int i=1; i<n; i++) {
        if (arr[i-1] != arr[i]) {
            if (arr[i] != arr[0])
                cout << "flip " << i << " to ";
            else
                cout << i-1 << endl;
        }
    }
    if (arr[n-1] != arr[0])
        cout << n-1;
}

// find max sum of k consecutive elements

// sliding window technique
int maxOfKElements (int arr[], int n, int k) {
    int currSum = 0;
    for (int i=0; i<k; i++)
        currSum += arr[i];
    int maxSum = currSum; 

    for (int i=k; i<n; i++) {
        currSum += (arr[i] - arr[i-k]);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

// given a array of NON NEGATIVE INTEGERS, find if there is a sub array with given sum
bool subArrWithGivenSum (int arr[], int n, int sum) {
    int start = 0, end = 0;
    int currSum = 0;
    while (end < n) {
        while (end<n && currSum<sum) {
            currSum += arr[end++];
        }
        if (currSum == sum) {
            cout << start << " " << end-1 << endl;
            return true;
        }
        while (start<end && currSum>sum) {
            currSum -= arr[start++];
        }
        if (currSum == sum) {
            cout << start << " " << end-1 << endl;
            return true;
        }
    }
    cout << -1 << " " << -1 << endl;
    return false;
}

// print first m 'nBonacci' numbers
void nBonacciNumbers (int n, int m) {
    
}

// prefix sum
// given a array return sum from ith element to jth element in O(1)
// just create a sum array that stores sum till ith element
int getSum (int sumArr[], int i, int j) {
    if (i == 0)
        return sumArr[j];
    return sumArr[j] - sumArr[i-1];
}

int* creatSumArr (int arr[], int n) {
    int* sumArr = (int*)malloc(n * sizeof(int));
    sumArr[0] = arr[0];
    for (int i=1; i<n; i++)
        sumArr[i] = sumArr[i-1] + arr[i];

    return sumArr;
}

// check if in given array an equillibrium point exists - point such that sum of elements before it = sum of elements after it
int equillibriumPoint (int arr[], int n) {
    int leftSum=0, rightSum=0;
    for (int i=0; i<n; i++)
        rightSum += arr[i];
    for (int i=0; i<n; i++) {
        rightSum -= arr[i];
        if (leftSum == rightSum)
            return i;
        leftSum += arr[i];
    }
    return -1;
}

// given n ranges find max repeating element
int maxRepeatingElement (int leftArr[], int rightArr[], int n, int maxx) {
    // maxx is the max element in rightArr
    int freqArr [maxx+1] = {0};
    for (int i=0; i<n; i++) {
        freqArr[leftArr[i]]++;
        freqArr[rightArr[i] + 1]--;
    }
    int maxFreq = freqArr[0];
    int index;
    for (int i=1; i<=maxx; i++) {
        freqArr[i] += freqArr[i-1];
        if (freqArr[i] > maxFreq) {
            maxFreq = freqArr[i];
            index = i;
        }
    }
    return index;
}
int main () {
    int arr[] = {4, -2, 2};
    //cout << secondLargest(arr, 5) << endl;
    int n = (sizeof(arr)/sizeof(arr[0]));
    traverse(arr, n);
    //reverseArr(arr, 5);
    //int n = removeDuplicates(arr, 5);
    //leftRotateD(arr, 8, 3);
    //traverse(arr, 8); 
    //cout << maxDiff(arr, 8) << endl;
    //cout << stockBuySell(arr, n) << endl;
    //cout << maxCons1s(arr, n) << endl;
    //cout << majorityElement(arr, n) << endl;
    //minimumFlips(arr, n);
    //cout << subArrWithGivenSum(arr, n, 15) << endl;
    // int* sumArray = creatSumArr(arr, n);
    // traverse(sumArray, n);
    // cout << getSum(sumArray, 2, 4) << endl;
    //cout << equillibriumPoint(arr, n) << endl;
    int leftArr[] = {1, 2, 3};
    int rightArr[] = {3, 5, 7};
    cout << maxRepeatingElement(leftArr, rightArr, 3, 7) << endl;
}
