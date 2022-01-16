#include "bits/stdc++.h"
using namespace std;

/* A Heap is a Tree-based data structure, which satisfies the below properties:
A Heap is a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible).

A Heap is either Min Heap or Max Heap. In a Min-Heap, the key at root must be minimum among all keys present in the Binary Heap. The same property must be recursively true for all nodes in the Tree. Max Heap is similar to MinHeap.

Binary Heap: A Binary Heap is a heap where each node can have at most two children. In other words, a Binary Heap is a complete Binary Tree satisfying the above-mentioned properties.

Since a Binary Heap is a complete Binary Tree, it can be easily represented using Arrays.
The root element will be at Arr[0].
Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node
*/

class myHeap {
    public:
    int* arr;
    int size;
    int capacity;

    myHeap (int c) {
        arr = new int [c];
        size = 0;
        capacity = c;
    }

    int getLeft (int i) { return (2*i + 1); }
    int getRight (int i) { return (2*i + 2); }
    int getParent (int i) { return (i-1)/2; }

    void insert (int x) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        int i = size;
        arr[size++] = x;

        while (i != 0 && arr[getParent(i)] > arr[i]) {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    }

    void traverse () {
        for (int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // compare parent's value, left child's value and right child's value, the minimum of these 3 values should be the parent's value. If it isn't, swap the parent's value with the minimum value and recursively call the function for the minimum value child
    // you will be the given the index of the node which may defiy the heap properties
    void heapify (int i) {
        int left = getLeft(i), right = getRight(i);
        int smallest = i;
        if (left < size && arr[left] < arr[smallest])
            smallest = left;
        if (right < size && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    } // O(H) H is log(n)
    // requires O(H) extra space


    // remove the minimum element of the heap
    // delete it, then replace it with the last element and then heapify
    int extractMin () {
        if (size == 0)
            return INT_MAX;
        if (size == 1) {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return arr[size];
    }

    // given an index i, decrease its value to val and then fix the binary tree
    // just update the value and then keep on swapping with parent till it reaches correct position
    void decreaseKey (int i, int val) {
        arr[i] = val;
        while (i != 0 && arr[getParent(i)] > arr[i]) {
            swap(arr[getParent(i)], arr[i]);
            i = getParent(i);
        }
    } // O(log n)

    // replace the node to be deleted with the last node and then call heapify operation with index i
    void deleteNode (int i) {
        arr[i] = arr[size-1];
        size--;
        heapify(i);
    }

    // given an array, build a binary heap
    // brute force way is to call heapify for all elements
    // Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
    // since leaf nodes are already heapified so start from right most non leaf node and go back from there.
    // if no of nodes = n, index of last node = n-1, parent of last node (which is the right most non leaf node) = (i-1)/2 = (n-1-1)/2 = (n-2)/2
    void buildHeap () {
        for (int i=(size-2)/2; i>=0; i--)
            heapify(i);
    }
    // O(n); time complexity calculation involves maths, check video

    // heap sort
    // selection sort using a heap
    // in selection sort we find the minimum element after each iteration; in heap sort we find minimum element using heap
    // to sort array in increasing order, we use max heap

    void maxHeapify (int* arr, int n, int i) {
        int largest=i, left=2*i+1, right=2*i+2;
        if (left < n && arr[largest] < arr[left])
            largest = left;
        if (right < n && arr[largest] < arr[right])
            largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    void buildHeap (int* arr, int n) {
        for (int i=(n-2)/2; i>=0; i--)
            maxHeapify(arr, n, i);
    }

    void heapSort (int* arr, int n) {
        buildHeap(arr, n);
        for (int i=n-1; i>=1; i--) {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
};

// sort a k-sorted array
// in a k sorted array, an element at index i in the original array will be present b/w the indices i-k and i+k (both inclusive) in the sorted array
// maintain a min heap for elements 0 to k (since the minimum element will be from the elements till index k in the original array)
// pick the element at the top of the heap, insert it at index 0, increment index, add the k+1 element in the heap and continue

void kSortedArray (int* arr, int n, int k) {
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i=0; i<=k; i++)
        pq.push(arr[i]);
    int index = 0; // to know where to insert the element

    for (int i=k+1; k<n; k++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
} // time complexity ??

// given an array, print the k largest elements (not necessarily in increasing order)
// make a min heap and add the first k elements to it
// start traversing from the (k+1)th element and if it is greater than the root of min heap, pop it and add the k+1 th element to the heap

void kLargestElements (int* arr, int n, int k) {
    priority_queue <int, vector <int>, greater<int>> pq;
    for (int i=0; i<k; i++)
        pq.push(arr[i]);

    for (int i=k; i<n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
// if we had converted the array to a max heap and then extracted the top k elements then the time complexity would have been O(n + klogn)
// when using a min heap time complexity is O(k + (n-k)logk) (compare it by selecting values of k like 1, 2 or n-1, n etc)

int main () {
    // myHeap h (10);
    // h.insert(1);
    // h.insert(3);
    // h.insert(4);
    // h.insert(5);
    // h.insert(6);
    // h.insert(7);
    // h.insert(2);

    // cout << h.size << endl;

    // int myArr[] = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};
    // h.arr = myArr;
    // h.size = 10;

    // h.traverse();
    // h.heapify(0);
    // h.traverse();

    // cout << h.extractMin() << endl;
    // h.traverse();

    // priority queue stl
    // by default max heap is used
    /* priority_queue <int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    } */

    // syntax for priority queue with min heap
    // first argument is data type, second argument is the underlying structure and the third argument is the comparison function.
    /* priority_queue <int, vector <int>, greater<int>> pq1;

    // priority queue using existing array
    int arr[] = {10, 5, 15};
    priority_queue <int> pq2 (arr, arr+3);
    // arr+3 instead of +2 because when we use v.end() it returns pointer to element beyond the last element
    vector <int> v = {4, 3, 6};
    priority_queue <int> pq3 (v.begin(), v.end()); */

    // if we create a priority queue for a user defined data structure such as a class we also need to overload comparison operator and provide it as argument

    int arr[] = {1, 2, 3, 4, 5, 6};
    kLargestElements(arr, 6, 3);

}