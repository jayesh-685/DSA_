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
        int element = size;
        arr[size++] = x;

        while (element != 0) {
            int parent = getParent(element);
            if (arr[element] > arr[parent])
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
    }
};

int main () {
    myHeap h (10);
    // h.insert(1);
    // h.insert(3);
    // h.insert(4);
    // h.insert(5);
    // h.insert(6);
    // h.insert(7);
    // h.insert(2);

    // cout << h.size << endl;

    int myArr[] = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};
    h.arr = myArr;
    h.size = 10;

    h.traverse();
    h.heapify(0);
    h.traverse();

    cout << h.extractMin() << endl;
    h.traverse();

}