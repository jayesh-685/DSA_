 #include "bits/stdc++.h"
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char x){
        data=x;
        next=NULL;
    }
};

int getElements (Node* head);
void traverse (Node *head);
int searchLL (Node *head, char x);
Node* insertEnd (Node *head, char element);
Node* deleteNode (Node *head, char element);
Node* insertMid (Node* head, char element);
Node *insertPos (Node *head, char data, int pos);
char middleElement (Node* head);
Node* getMax (Node* head);
Node* getMin (Node* head);
void detectRemoveLoop (Node* head);
int maxNodePos (Node* head, Node* maxNode);
int minNodePos (Node* head, Node* minNode);
void removeCommonNode (Node* head, Node* node);

int main () {
    string s;
    cin >> s;

    Node* head = NULL;

    for (int i=0; i<s.length(); i++) {
        int pos = searchLL(head, s[i]);
        if (pos == -1) {
            head = insertEnd(head, s[i]);
        } else {
            head = deleteNode(head, s[i]);
            head = insertMid(head, s[i]);
        }
    }
    //traverse(head);
    Node* maxNode = getMax(head);
    Node* minNode = getMin(head);
    //cout << minNode->data << " " << maxNode->data << endl;
    int maxPos = maxNodePos(head, maxNode);
    int minPos = minNodePos(head, minNode);
    //cout << minPos << " " << maxPos << endl;

    Node* head2 = NULL;
    if (minNode->next != maxNode)
        head2 = minNode->next;
    minNode->next = maxNode;
    //cout << head->next->data << " " << head2 << endl;
    
    if (maxPos > minPos) 
        removeCommonNode(head2, maxNode);
    else 
        detectRemoveLoop(head);
    
    
    traverse(head);
    traverse(head2);
}

void traverse (Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int searchLL (Node *head, char x) {
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

Node* insertEnd (Node *head, char element) {
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

Node* deleteNode (Node *head, char element) {
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

int getElements (Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* insertMid (Node* head, char element) {
    int noOfElements = getElements(head);
    if (noOfElements%2 == 0) {
        head = insertPos(head, element, (noOfElements/2)+1);
    } else {
        char mid = middleElement(head);
        if (mid < element)
            head = insertPos(head, element, ((noOfElements+1)/2)+1);
        else
            head = insertPos(head, element, ((noOfElements+1)/2)); 
    }

    return head;
}

Node *insertPos (Node *head, char data, int pos) {
    Node *newNode = new Node (data);

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

char middleElement (Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

Node* getMax (Node* head) {
    Node* maxNode = head;
    while (head != NULL) {
        if (head->data > maxNode->data)
            maxNode = head;
        head = head->next;
    }
    return maxNode;
}

Node* getMin (Node* head) {
    Node* minNode = head;
    while (head != NULL) {
        if (head->data < minNode->data)
            minNode = head;
        head = head->next;
    }
    return minNode;
}

void detectRemoveLoop (Node* head) {
    /* if (checkCircularLL(head)) {
        Node* curr = head->next;
        while (curr->next != head)
            curr = curr->next;
        curr->next = NULL;
        return;
    } */
        
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;

    // if linked list is circular
    if (slow == head && fast == head) {
        fast = head->next;
        while (fast->next != head)
            fast = fast->next;
        fast->next = NULL;
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int maxNodePos (Node* head, Node* maxNode) {
    int pos = 1;
    while (head != maxNode) {
        head = head->next;
        pos++;
    }
    return pos;
}
int minNodePos (Node* head, Node* minNode) {
    int pos = 1;
    while (head != minNode) {
        head = head->next;
        pos++;
    }
    return pos;
}

void removeCommonNode (Node* head, Node* node) {
    if (head == NULL)
        return;
    while (head->next != node) {
        head = head->next;
        if (head == NULL)
            return;
    }
    head->next = NULL;
} 

