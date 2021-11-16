#include "bits/stdc++.h"
using namespace std;

// have 2 pointers next and prev
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
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

Node* insertBegin (Node* head, int data) {
    Node* newNode = new Node (data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node* insertEnd (Node* head, int data) {
    Node* newNode = new Node (data);
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Node* reverseDLL (Node* head) {
//     if (head == NULL)
//         return head;
//     int count = 1;
//     Node* begin = head;
//     Node* end = head;
//     while (end->next != NULL) {
//         count++;
//         end = end->next;
//     }
//     for (int i=1; i<=count/2; i++) {
//         int temp = begin->data;
//         begin->data = end->data;
//         end->data = temp;
//         begin = begin->next;
//         end = end->prev;
//     }
//     return head;
// }

Node* reverseDLL (Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* curr = head;
    Node* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

Node* deleteHead (Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    } 
    Node* newHead = head->next;
    newHead->prev = NULL;
    delete head;
    return newHead;
}

Node* deleteTail (Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}

void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node* newNode = new Node (data);
   Node* curr = head;
   if (head == NULL) head = newNode;
   for (int i=0; i<pos; i++) {
       if (curr->next == NULL)
        break;
       curr = curr->next;
   }
   newNode->next = curr->next;
   curr->next = newNode;
   newNode->prev = curr;
   if (newNode->next != NULL)
    newNode->next->prev = newNode;
     
}

int main () {
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->prev = head;
    // head->next->next = new Node (30);
    // head->next->next->prev = head->next;
    // traverse(head);
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    traverse(head);
    addNode(head, 4, 35);
    traverse(head);
}
