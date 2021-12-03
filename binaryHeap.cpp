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
        if (size == capacity)
            cout << "Heap is full" << endl;
            return;
        int element = size;
        arr[size++] = x;

        cout << size << endl;

        while (element != 0) {
            int parent = getParent(element);
            if (arr[element] < arr[parent])
                break;
            else {
                swap(arr[element], arr[parent]);
                element = parent;
            }
        }
    }

    void traverse () {
        for (int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify (myHeap* h) {
    
}

int main () {
    myHeap h (10);
    // h.insert(18);
    // h.insert(3);
    // h.insert(46);
    // h.insert(12);
    // h.insert(7);

    int myArr[] = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};
    h.arr = myArr;
    h.size = 10;

    h.traverse();
    heapify(&h);
    h.traverse();

}