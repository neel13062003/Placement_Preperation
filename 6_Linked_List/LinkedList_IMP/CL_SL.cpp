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
    if (head == nullptr)
        return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void InsertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void InsertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void InsertBwNodePosition(Node*& head, int data, int position) {
    if (position <= 1) {
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeleteNode(Node*& head, int position) {
    if (head == nullptr)
        return;

    if (position == 1) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head)
        return;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

int main() {
    Node* head = nullptr;

    InsertAtHead(head, 10);
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
