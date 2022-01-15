#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


void traverse (Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


void recursionTraverse (Node *head) {
    if (head == NULL)
        return;
    cout << head->data << endl;
    recursionTraverse(head->next);
}

int getElements (Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* insertBegin (Node *head, int element) {
    // to add an element at start of linked list
    Node *newHead = new Node (element);
    newHead->next = head;
    return newHead;
}

Node* insertEnd (Node *head, int element) {
    Node *temp = new Node (element);
    if (head == NULL) {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// don't forget to deallocate memory of the nodes you are deleting
Node *deleteHead (Node *head) {
    if (head == NULL)
        return head;
    Node *temp = head->next;
    delete head;
    return temp;
}

Node *deleteTail (Node *head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
    
}

Node *insertPos (Node *head, int data, int pos) {
    Node *newNode = new Node (data);

    // we have to change head if pos is 1
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    for (int i=1; i<pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

/*
int searchLL (Node * head, int x) {
    Node *curr = head;
    int pos = 1;
    while (curr != NULL) {
        if (curr->data == x)
	        return pos;
        curr = curr->next;
        pos++;
    }
    return -1;
}
*/

// recursive solution
// int searchLL (Node * head, int x, int pos) {
//     if (head == NULL)
//         return -1;
//     if (head->data == x)
//         return pos;
//     return searchLL (head->next, x, ++pos);
// }

// recursive with 2 arguments

int searchLL (Node *head, int x) {
    if (head == NULL)
        return -1;
    if (head->data == x)
        return 1;
    else {
        int result = searchLL (head->next, x);
        if (result == -1)
            return -1;
        else 
            return result + 1;
    }
}

Node* insertSorted (Node* head, int x) {
    // insert a node in given linked list such that it remains sorted
    Node* newNode = new Node (x);
    if (head == NULL) 
        return newNode;
    if (head->data >= x) {
        newNode->next = head;
        return newNode;
    }
    Node* curr = head;
    while (curr->next != NULL && curr->next->data < x)
        curr = curr->next;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

void middleElement (Node* head) {
// by traversing only once
    if (head == NULL) 
        return ;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
}

/* void nFromEnd (Node* head, int n) {
    // print nth element from the end
    int count = 1;
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }
    int steps = count-n;
    if (steps < 0)
        return;
    curr = head;
    for (int i=0; i<steps; i++)
        curr = curr->next;
    cout << curr->data << endl;
} */

// better two pointer approach

void nFromEnd (Node* head, int n) {
    Node* first = head;
    Node* second = head;
    for (int i=1; i<n; i++) {
        first = first->next;
        if (first == NULL)
            return;
    }
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    cout << second->data << endl;
}

Node* reverseLL (Node* head) {
    Node* before = NULL;
    Node* curr = head;
    Node* after = head;
    while (after != NULL) {
        after = after->next;
        curr->next = before;
        before = curr;
        curr = after;
    }
    return before;
}

Node* recursiveReverse (Node* head) {
    // assume that if we pass the complete linked list except the first element it will return the last node as the head and the ll would be reversed.
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    Node* restHead = recursiveReverse(head->next);
    Node* restTail = head->next;  // it would be the second element
    restTail->next = head;
    head->next = NULL;
    return restHead;
}

/* Node* recursiveReverse (Node* head) {
    Node* restHead = recursiveReverse(head->next);
    
} */

// since we will never be changing head return type is void
void removeDuplicate (Node* head) {
    if (head == NULL) // we can cover this cover case in while loop as well 
        return;
    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->data != curr->next->data) {
            curr = curr->next;
        } else {
            Node* duplicate = curr->next;
            curr->next = curr->next->next;
            delete duplicate;
        }
    }
}

Node* deleteNode (Node* head, int element) {
    if (head->data == element) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    
    Node* curr = head;
    
    while (curr->next->data != element)
        curr = curr->next;
    
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

Node* reverseK (Node* head, int k) {
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    while (curr != NULL && k--) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* reverseinK (Node* head, int k) {
    
}

int main() 
{ 
    // simple implementation
    // Node *head=new Node(10);
	// Node *temp1=new Node(20);
	// Node *temp2=new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
    // traverse(head);

    //compact implementation for 3 nodes
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->next = new Node (30);
    //traverse(head);
    //recursionTraverse(head);    
    // even after using the traverse function we still get 10 20 30 from the next line because a copy of the pointer is made and the original pointer stays at the same position
    //cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    // Node *head = NULL;
    // head = insertBegin(head, 5);
    // head = insertBegin(head, 10);
    // head = insertBegin(head, 15);
    // head = insertBegin(head, 20);
    // traverse(head);

    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    traverse(head);
    //head = deleteHead(head);
    //head = deleteTail(head);
    head = insertPos(head, 25, 3);
    // traverse(head);
    //cout << searchLL (head, 10) << endl;
    // head = insertSorted(head, 20);
    // traverse(head);  
    //middleElement(head);
    //nFromEnd(head, 4);
    //removeDuplicate(head);
    //head = deleteNode(head, 40);
    traverse(head);
    //cout << getElements(head);
    return 0;
} 
