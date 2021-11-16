#include "bits/stdc++.h"
using namespace std;

//next of last node is head/first node
// can be both singly linked and doubly linked

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
// in a single element circular linked list head->next = head;

void traverse (Node* head) {
    if (head == NULL)
        return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

// O(n)
// Node* insertBegin (Node* head, int data) {
//     Node* newHead = new Node (data);
//     if (head == NULL) {
//         newHead->next = newHead;
//     } else {
//         Node* curr = head;
//         while (curr->next != head)
//             curr = curr->next;
//         curr->next = newHead;
//         newHead->next = head;
//     }
//     return newHead;
// }

// O(1)  insert the new element after the head then exchange the head and newNode data
Node* insertBegin (Node* head, int data) {
    if (head == NULL) {
        Node* newNode = new Node (data);
        newNode->next = newNode;
        return newNode;
    }
    // here I created new node with exchanged data or you can create new node first and then exchange data
    Node* newHead = new Node (head->data);
    head->data = data;  
    newHead->next = head->next;
    head->next = newHead;
    return head;
}

// Node* insertEnd (Node* head, int data) {
//     Node* newEnd = new Node (data);
//     if (head == NULL) {
//         newEnd->next = newEnd;
//         return newEnd;
//     }
//     Node* curr = head;
//     while (curr->next != head) 
//         curr = curr->next;
//     curr->next = newEnd;
//     newEnd->next = head;
//     return head;
// }

Node* insertEnd (Node* head, int data) {
    Node* newEnd = new Node (data);
    if (head == NULL) {
        newEnd->next = newEnd;
        return newEnd;
    }
    newEnd->next = head->next;
    head->next = newEnd;
    int temp = head->data;
    head->data = newEnd->data;
    newEnd->data = temp;
    return newEnd;
}

// Node* deleteHead (Node* head) {
//     if (head == NULL)
//         return NULL;
//     if (head->next == NULL) {
//         delete head;
//         return NULL;
//     }
//     Node* curr = head;
//     while (curr->next != head)
//         curr = curr->next;
//     curr->next = head->next;
//     delete head;
//     return curr->next;
// }

Node* deleteHead (Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node* temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

Node* deleteKthNode (Node* head, int k) {
    // assuming no of nodes >= k 
    Node* curr = head;
    for (int i=1; i<k-1; i++) {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head; 
}

bool detectLoopFloydCycle (Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
// The distance b/w fast and slow node increases by one after each titration and when it becomes equal to length of the loop they meet and we know it's a loop
// O(n+m) where n is the no of nodes in the loop and m are the remaining nodes so it equivalent to O(N) where N is no of nodes in the linked list

int main () {
    // Node *head=new Node(10);
	// Node *temp1=new Node(20);
	// Node *temp2=new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
    // temp2->next = head;
    // traverse(head);
    // head = insertBegin(head, 5);
    // head = insertEnd(head, 40);
    // traverse(head);
    // Node* temp1 = NULL;
    // temp1 = insertEnd(temp1, 29);
    // traverse(temp1);
    // Node* temp2 = NULL;
    // temp2 = insertBegin(temp2, 6);
    // traverse(temp2);
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    traverse(head);
    // head = insertEnd(head, 50);
    // traverse(head);
    head = deleteKthNode(head, 2);
    traverse(head);
}

