#include <iostream>
#include <algorithm>

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void sortList() {
        // Convert the linked list to a vector
        vector<int> values;
        Node* current = head;
        while (current != nullptr) {
            values.push_back(current->data);
            current = current->next;
        }

        // Sort the vector
        std::sort(values.begin(), values.end());

        // Update the linked list with sorted values
        current = head;
        for (int value : values) {
            current->data = value;
            current = current->next;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insertAtHead(10);
    myList.insertAtHead(12);
    myList.insertAtHead(8);
    myList.insertAtHead(16);
    myList.insertAtHead(5);

    std::cout << "Original List: ";
    myList.printList();

    myList.sortList();

    std::cout << "Sorted List: ";
    myList.printList();

    return 0;
}
