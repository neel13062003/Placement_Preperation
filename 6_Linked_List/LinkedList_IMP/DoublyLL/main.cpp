#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // Destructor
    ~Node() {
        cout << "Memory is freed for node " << data << std::endl;
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
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void InsertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void InsertBwNodePosition(Node*& head, int data, int position) {
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
        InsertAtTail(head, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void DeleteNode(Node*& head, int position) {
    if (head == nullptr)
        return;

    Node* temp = head;

    if (position == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    int count = 1;
    while (count < position && temp != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
        return;

    temp->prev->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main() {
    Node* head = nullptr;

    Node* node1 = new Node(10);
    head = node1;

    cout << "First - > ";
    printLL(head);

    InsertAtHead(head, 12);
    cout << "Second - > ";
    printLL(head);

    InsertAtTail(head, 13);
    cout << "Third - > ";
    printLL(head);

    InsertBwNodePosition(head, 14, 2);
    cout << "Fourth - > ";
    printLL(head);

    DeleteNode(head, 2);
    cout << "Fifth - > ";
    printLL(head);

    return 0;
}
