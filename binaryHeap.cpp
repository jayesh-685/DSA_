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
// when using a min heap time complexity is O(k + (n-k)logk) (compare it by selecting small values of k so that it can be ignored or large values of k like n)


// given an integer x and an array, print the k closest elements to x in the array
// create a priority queue of pair of diff between arr[i] and x and the index of arr[i]
// then use the same approach as k largest element except this time use it to find elements with smallest difference
void kClosestElements (int* arr, int n, int k, int x) {
    priority_queue <pair <int, int>> maxHeap;

    // O(klogk)
    for (int i=0; i<k; i++) 
        maxHeap.push({abs(arr[i]-x), i});

    // O((n-k)logk)
    for (int i=k; i<n; i++) {
        if (abs(arr[i]-x) < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({abs(arr[i]-x), i});
        }
    }

    // O(klogk)
    while (!maxHeap.empty()) {
        cout << arr[maxHeap.top().second] << " ";
        maxHeap.pop();
    }
}
// O(nlogk)

struct triplet {
    int val, arrPos, elementPos;
    triplet (int v, int a, int e) {
        val = v; arrPos = a; elementPos = e;
    }
};

struct myCompare {
    bool operator () (triplet t1, triplet t2) {
        return t1.val > t2.val;
    }
};

// given k sorted arrays, merge them into a single array
/* Create a min Heap and insert the first element of all k arrays.
Run a loop until the size of MinHeap is greater than zero.
Remove the top element of the MinHeap and print the element.
Now insert the next element from the same array in which the removed element belonged. */
// to keep track of which array is the minimum element from and index of new element to be added to the heap we creat a struct triplet
void mergeKSortedArray (vector <vector <int>> v) {
    vector <int> ans;
    priority_queue <triplet, vector <triplet>, myCompare> minHeap;

    for (int i=0; i<v.size(); i++) 
        minHeap.push(triplet(v[i][0], i, 0));
    
    while (!minHeap.empty()) {
        triplet top = minHeap.top();
        minHeap.pop();
        ans.push_back(top.val);
        int ap = top.arrPos, ep = top.elementPos;
        if (ep+1 < v[ap].size()) 
            minHeap.push(triplet(v[ap][ep+1], ap, ep+1));
    }

    for (auto x: ans)
        cout << x << " ";
    cout << endl;
}
// O(nkLogk), n is the max no of elements in any array

// median from a data stream
// given a data stream, find median at each point
// brute force way is to maintain the stream in sorted order using insertion sort while adding a new element
// O(n^2)

// we use a max heap and a min heap to divide the stream in two parts, one for elements larger than the effective median and one for smaller than the effective median. difference in no of elements in min Heap and max heap is atmost 1. when no of elements in both heaps is equal and we to add one more element we insert it to the left half (maxHeap). when we want to insert num to maxHeap (left half) but the no is larger than right half top then we insert right half top to left half and then insert num to right half and vice versa
class MedianFinder {
public:
    
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
        } else if (maxHeap.size() == minHeap.size()) {
            if (num <= minHeap.top()) {
                maxHeap.push(num);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        } else {
            if (num >= maxHeap.top()) {
                minHeap.push(num);
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size())
            return (double)(minHeap.top() + maxHeap.top())/2;
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

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

    /* int arr[] = {1, 2, 3, 4, 5, 6};
    kLargestElements(arr, 6, 3); */

    // int arr[] = {20, 40, 5, 100, 150};
    // kClosestElements(arr, 5, 3, 100);

    vector <vector <int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    mergeKSortedArray(v);

}