#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Destructor
    ~Node() {
        cout << "Memory is freed for node " << data << endl;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (tail == nullptr) {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void InsertBwNodePosition(Node*& head, Node*& tail, int data, int position) {
    if (position <= 1) {
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        InsertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeleteNode(Node*& head, int position) {
    if (head == nullptr)
        return;

    Node* temp = head;

    if (position == 1) {
        head = head->next;
        delete temp;
        return;
    }

    int count = 1;
    Node* prev = nullptr;
    while (count < position && temp != nullptr) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
        return;

    prev->next = temp->next;
    delete temp;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    Node* node1 = new Node(10);
    head = node1;
    tail = node1;

    cout << "First - > ";
    printLL(head);

    InsertAtHead(head, 12);
    cout << "Second - > ";
    printLL(head);

    InsertAtTail(tail, 13);
    cout << "Third - > ";
    printLL(head);

    InsertBwNodePosition(head, tail, 14, 2);
    cout << "Fourth - > ";
    printLL(head);

    cout << "Head - > " << head->data << endl;
    cout << "Tail - > " << tail->data << endl;

    DeleteNode(head, 2);
    cout << "Fifth - > ";
    printLL(head);

    return 0;
}



/*Node *node = new Node(d);
memory allcoate in heap if you want to free memory you should use destructor for that java automaticaly delocate memory but in c++ you should delocate memory manually
*/
