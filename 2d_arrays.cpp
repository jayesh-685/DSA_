// 2-d arrays
#include "bits/stdc++.h"
using namespace std;

void spiralMatrixTraverse (int **arr, int n, int m) {

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;
    int direction = 0;

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i=left; i<=right; i++)
                cout << arr[top][i] << " ";
            top++;
        } else if (direction == 1) {
            for (int i=top; i<=bottom; i++)
                cout << arr[i][right] << " ";
            right--;
        } else if (direction == 2) {
            for (int i=right; i>=left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        } else if (direction == 3) {
            for (int i=bottom; i>=top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
        cout << endl;
        direction = (++direction)%4;
    }
}

void transposeOfMatrix (int **arr, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
} 

void matrixMultiplication (int **arr1, int n, int m, int **arr2, int o, int p) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<p; j++) {
            int sum = 0;
            for (int k=0; k<m; k++) 
                sum += arr1[i][k] * arr2[k][j];
            cout << sum << " ";
        }
        cout << endl;
    }
}

bool searchInMatrix (int **arr, int n, int m, int k) {
    // we have to find k in matrix arr
    // linear search would be the brute force method
    // for an optimized way, each array should be in ascending order
    // consider a pointer at top right
    // if k is lesser than the current element, you go left
    // if k is greater than the current element, you go down
    int r = 0, c = m-1;
    while (r < n && c >= 0) {
        if (arr[r][c] == k) {
            cout << r << " " << c << endl;
            return true;
        } else if (k < arr[r][c]) {
            c--;
        } else {
            r++;
        }
    }
    return false;

    // if the matrix is such that the first element of each row is greater than the last element of last row then we can use a better approach
    // the matrix then becomes equivalent to a sorted 1d array
    // but if we create a temp array from a matrix then it will increase time comlexity
    // so we give a index to each element in the matrix and then determine the row and column no using that index
    // for ex if the index of a element is 5 then its row no is 5/(no of columns) and column no is 5/(no of columns)
    // them we simply use binary search

    // n = no of rows  // m = no of columns

    int start = 0, end = n*m - 1;
    int mid = (start + end)/2;
    cout << start << " " << mid << " " << end << endl;

    while (start <= end) {
        int num = arr[mid/m][mid%m];
        cout << num << endl;
        if (num == k) {
            return true;
        } else if (num > k) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        mid = (start + end)/2;
    }
    return false;
} 

int main () {

    // for multiplication
    /* int n, m;
    cin >> n >> m;
    int **arr1 = (int **)malloc(n * sizeof(int*));
    for (int i=0; i<n; i++)
        arr1[i] = (int*)malloc(m * sizeof(int));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr1[i][j];
        }
    }

    int o, p;
    cin >> o >> p;
    int **arr2 = (int **)malloc(o * sizeof(int*));
    for (int i=0; i<o; i++)
        arr2[i] = (int*)malloc(p * sizeof(int));
    for (int i=0; i<o; i++) {
        for (int j=0; j<p; j++) {
            cin >> arr2[i][j];
        }
    } */

    // matrixMultiplication(arr1, n, m, arr2, o, p);

    int n, m;
    cin >> n >> m;
    int **arr = (int**)malloc(n * sizeof(int*));
    for (int i=0; i<n; i++)
        arr[i] = (int*)malloc(m * sizeof(int));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
            cin >> arr[i][j];
    }

    int k;
    cin >> k;

    //cout << searchInMatrix(arr, n, m, k) << endl;
    return 0;
}

