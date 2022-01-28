#include "bits/stdc++.h"
using namespace std;

/* Problem: You are given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Example 1: Consider the following 3 activities sorted by
finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2: Consider the following 6 activities 
sorted by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and the start time is more than or equal to the finish time of previously selected activity. We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.

To do this:
Sort the activities according to their finishing time.
Select the first activity from the sorted array and print it.
Do following for remaining activities in the sorted array.
If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.

Proof that first activity is always selected in the optimal solution:
Consider a set s1, having n elements, which includes first activity and set s2, having m elements, which doesn't include first activity
if s2 is the better solution, then m > n
if we exclude the first element of s2 then no of elements in s2 = m-1 and since first element of s1 will always be less than first element of s2, it can be replaced with first element of s1 which means that m-1 + 1 = n i.e m = n which contradicts our assumption */

bool myCompare (pair <int, int> a, pair <int, int> b) {
    return (a.second < b.second);
}

int maxActivities (pair<int, int> arr[], int n) {
    sort(arr, arr+n);
    int prev = 0;
    int count = 1;
    for (int curr=1; curr<n; curr++) {
        if (arr[curr].first >= arr[prev].second) {
            prev = curr;
            count++;
        }
    }

    return count;
}

// Huffman coding
/* Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code.
The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 
Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is the prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.

There are mainly two major parts in Huffman Coding:
1. Build a Huffman Tree from input characters.
2. Traverse the Huffman Tree and assign codes to characters.

Steps to build Huffman Tree
Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree. 

Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
 
Create a new internal node with a frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete. */

// huffman node
struct hNode {
    char ch;
    int freq;
    hNode* left;
    hNode* right;
    hNode (char c, int f, hNode *l=NULL, hNode *r=NULL) {
        ch = c;
        freq = f;
        left = l;
        right = r;
    }
};

struct compare {
    bool operator () (hNode* l, hNode* r) {
        return l->freq < r->freq;
    }
};

// see video
void printCodes (hNode* root, string str) {
    if (root->ch != '$') {
        cout << root->ch << " : " << str << endl;
        return;
    }

    printCodes(root->left, str+"0");
    printCodes(root->right, str+"1");
}

void printHCodes (char arr[], int freq[], int n) {
    priority_queue <hNode*, vector<hNode*>, compare> pq;

    // O(nlogn)
    for (int i=0; i<n; i++) {
        pq.push(new hNode(arr[i], freq[i]));
    }

    // O(nlogn)
    while (pq.size() > 1) {
        hNode* left = pq.top();
        pq.pop();
        hNode* right = pq.top();
        pq.pop();
        hNode* newNode = new hNode('$', left->freq+right->freq, left, right);
        pq.push(newNode);
    }

    printCodes(pq.top(), "");   // theta(n)
}
// overall time complexity: O(nLogn)
// overall space complexity: Theta(n)


int main () {

    // pair<int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};
    // cout << maxActivities(arr, 3);

    char arr[] = {'a', 'b', 'c', 'd'};
    int freq[] = {34, 12, 36, 74};
    printHCodes(arr, freq, 4);
}