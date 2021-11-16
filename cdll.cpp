// circular doubly linked list
#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node (int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

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

Node* insertHead (Node* head, int data) {
    Node* newHead =  new Node (data);
    if (head == NULL) {
        newHead->next = newHead;
        newHead->prev = newHead;
        return newHead;
    }
    newHead->prev = head->prev;
    head->prev = newHead;
    newHead->next = head;
    newHead->prev->next = newHead;
    return newHead;
}

Node* insertEnd (Node* head, int data) {
    // basically insertHead except we will return the same head instead of newEnd
    Node* newEnd = new Node (data);
    if (head == NULL) {
        newEnd->next = newEnd;
        newEnd->prev = newEnd;
        return newEnd;
    }
    newEnd->prev = head->prev;
    head->prev = newEnd;
    newEnd->next = head;
    newEnd->prev->next = newEnd;
    return head;
}

int main () {
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    traverse(head);
}