#include <iostream>

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
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    // Destructor
    ~CircularDoublyLinkedList() {
        if (head == nullptr)
            return;

        Node* current = head;
        while (current->next != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete current;
        head = nullptr;
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << std::endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << std::endl;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->prev = head;
            head->next = head;
        } else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->prev = head;
            head->next = head;
        } else {
            newNode->prev = head->prev;
            newNode->next = head;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void insertAfterNode(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "Previous node is null" << std::endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void deleteNode(Node* node) {
        if (head == nullptr || node == nullptr)
            return;

        if (head == node && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        if (head == node)
            head = node->next;

        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
};

int main() {
    CircularDoublyLinkedList myList;

    myList.insertAtHead(10);
    cout << "First - > ";
    myList.printList();

    myList.insertAtHead(12);
    cout << "Second - > ";
    myList.printList();

    myList.insertAtTail(13);
    cout << "Third - > ";
    myList.printList();

    Node* secondNode = myList.insertAfterNode(myList.head, 14);
    cout << "Fourth - > ";
    myList.printList();

    myList.deleteNode(secondNode);
    cout << "Fifth - > ";
    myList.printList();

    return 0;
}
