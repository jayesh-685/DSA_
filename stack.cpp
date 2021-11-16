#include "bits/stdc++.h"
using namespace std;

// array implementation
/* struct myStack {
    int* arr;
    int cap;    // capacity of stack;
    int top;    // index of topmost element

    myStack (int c) {
        cap = c;
        arr = new int [cap];
        top = -1;   // since stack is empty index of top most element is -1
    }

    // to add an element to the stack
    void push (int x) {
        // corner case if stack is full
        if (top == cap-1) { 
            cout << "stack at max capacity" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // returning last element and removing it
    int pop () {
        // corner case if stack is empty
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        int last = arr[top];
        top--;
        return last;
    }

    int peek () {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    int size () {
        return top+1;
    }

    bool isEmpty () {
        return (top == -1);
    }
}; */

// vector implementation
/* struct myStack {
    vector <int> vec;

    // to add an element to the stack
    void push (int x) {
        vec.push_back(x);
    }

    // returning last element and removing it
    int pop () {
        int last = vec.back();
        vec.pop_back();
        return last;
    }

    int peek () {
        return vec.back();
    }

    int size () {
        return vec.size();
    }

    bool isEmpty () {
        return vec.empty();
    }
}; */

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

// insert at head and delete head since deleting at tail won't be possible in O(1) in singly linke list. Possible in doubly linked list though
// all operations are O(1)
struct myStack {
    Node* head = NULL;
    int count = 0;

    void push (int n) {
        Node* newNode = new Node (n);
        newNode->next = head;
        head = newNode;
        count++;
    }

    int pop () {
        if (head == NULL)
            return INT_MIN;
        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return res;
    }

    int size () {
        return count;
    }

    int peek () {
        if (head == NULL)
            return INT_MIN;
        return head->data;
    }

    bool isEmpty () {
        return (head == NULL);
    }

};

int main () {
    myStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << " " << s.size() << endl;
    cout << s.pop() << " " << s.peek() << " " << s.size() << endl;

    stack <int> st;
    st.push(5);
    st.push(15);
    st.push(25);
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}