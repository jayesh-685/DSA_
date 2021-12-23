#include "bits/stdc++.h"
using namespace std;

void insertion_sort (int* arr, int n) {
    for (int i=1; i<n; i++) {
        int curr = arr[i];
        int j=i-1;
        while (j>=0 && arr[j] > curr) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

void printArray (int* arr, int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main () {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    printArray(arr, n);
}