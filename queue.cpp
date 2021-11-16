#include "bits/stdc++.h"
using namespace std;

/* A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added */

/* struct myQueue {
    int* arr;
    int size, cap;

    myQueue (int x) {
        arr = new int [x];
        size = 0;
        cap = x;
    }

    bool isEmpty () {
        return (size==0);
    }

    bool isFull () {
        return (size==cap);
    }
    void enqueue (int n) {
        if (isFull())
            return;
        arr[size] = n;
        size++;
    }

    void dequeue () {
        if (isEmpty()) 
            return;
        for (int i=0; i<size-1; i++)
            arr[i] = arr[i+1];
        size--;
    }

    int getFront () {
        if (isEmpty())
            return INT_MIN;
        return arr[0];
    }

    int getRear () {
        if (isEmpty())
            return INT_MIN;
        return arr[size-1];
    }
        
}; */
// here dequeue operation is O(n) to make it O(1) we use circular array

/* struct myQueue {
    int* arr;
    int size, cap, front;

    myQueue (int x) {
        cap = x;
        size = 0;
        front = 0;
        arr = new int [cap];
    }

    bool isEmpty () {
        return (size==0);
    }

    bool isFull () {
        return (size==cap);
    }

    void enqueue (int n) {
        if (isFull())
            return;
        int rear = (front + size)%cap;
        arr[rear] = n;
        size++;
    }    

    void dequeue () {
        if (isEmpty())
            return;
        front = (front+1)%cap;
        size--;
    }

    int getFront () {
        if (isEmpty())
            return INT_MIN;
        return arr[front];
    }

    int getRear () {
        if (isEmpty())
            return INT_MIN;
        return arr[(front+size-1)%cap];
    }
}; */

// implementing queue using linked list

/* struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

struct myQueue {
    Node* front;
    Node* rear;
    int size;

    myQueue () {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    
    bool isEmpty () {
        return (front == NULL);
    }

    void enqueue (int n) {
        Node* newNode = new Node (n);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue () {
        if (isEmpty())
            return;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        size--;
    }

    int getFront () {
        if (isEmpty())
            return INT_MIN;
        return front->data;
    }

    int getRear () {
        if (isEmpty())
            return INT_MIN;
        return rear->data;
    }

    int getSize () {
        return size;
    }
}; */

// implement stack using queue

/* struct myStack {
    queue <int> q1, q2;

    int top () {
        return q1.front();
    } 

    void push (int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop () {
        q1.pop();
    }

    int size () {
        return q1.size();
    }
}; */
// here we made the push function costly, to make the pop function costly instead, we dequeue everything except the last element from q1 and enqueue to q2. then delete the last element from q1 and then swap names of q1 and q2

/* void pop {
    while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    queue <int> temp = q1;
    q1 = q2;
    q2 = temp;
} */

// implement stack using 1 queue
// we will just push at the back and then pop from the front
/*
void push (int x) {
    int s = q.size();
    q.push(x);

    for (int i=0; i<s; i++) {
        q.push(q.front());
        q.pop();
    }
} */

// queue using stack

// struct myQueue {
//     stack <int> s1;
//     stack <int> s2;

//     void enqueue (int x) {
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     void dequeue () {
//         s1.pop();
//     }

//     // if we want to make the dequeue operation costly instead

//     /* void dequeue () {
//         while (s1.size() != 1) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.pop();
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     } */

// };

// using one stack only:

struct myQueue {
    stack <int> s;

    int getRear () {
        return s.top();
    }

    void push (int x) {
        s.push(x);
    }

    void pop () {
        if (s.size() == 1) {
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop(); 
        pop();
        s.push(temp);
    }
};

// iterative reverse
/* void reverse (queue <int> &q) {
    stack <int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
} */

// recursive reverse
void reverse (queue <int> &q) {
    if (q.size() == 1)
        return;
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

void traverse (queue <int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main () {
    /* myQueue q;
    cout << q.isEmpty() << endl;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    cout << q.isEmpty() << endl;
    cout << q.getFront() << " " << q.getRear() << " " << q.getSize() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << " " << q.getSize() << endl;

    // queue in c++ STL
    // push for enqueue and pop for dequeue

    queue <int> u;
    u.push(5);
    u.push(10);
    u.push(15);
    u.push(20);
    cout << u.front() << " " << u.back() << endl;
    u.pop();
    cout << u.front() << " " << u.back() << endl;

    while (!u.empty()) {
        cout << u.front() << " ";
        u.pop();
    } */
    
    // queue is a container adapter
    // by default implemented using dequeue
    // all operations are O(1)

    /* myStack q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << q.top() << endl;
    q.pop();
    cout << q.size() << endl; */

    /* myQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << q.getRear() << endl;
    q.pop();
    cout << q.getRear() << endl; */

    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    traverse(q);
    //reverse(q);
    traverse(q);
}