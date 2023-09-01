#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    void insertBSTNow(Node* &root, int d) {
        if (!root) {
            root = new Node(d);
            return;
        }
        if (root->data > d) {
            insertBSTNow(root->left, d);
        } else {
            insertBSTNow(root->right, d);
        }
    }

    void insertBST(int data) {
        insertBSTNow(root, data);
    }

    void deleteFinal(Node* &root, int d) {
        if (!root) return;

        if (root->data == d) {
            if (!root->left && !root->right) { // Case 1: Leaf node
                delete root;
                root = nullptr;
            } else if (!root->left || !root->right) { // Case 2: Node with one child
                Node* temp = root;
                if (root->left) root = root->left;
                else root = root->right;
                delete temp;
            } else { // Case 3: Node with two children
                Node* temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                root->data = temp->data;
                deleteFinal(root->left, temp->data);
            }
        } else if (root->data > d) {
            deleteFinal(root->left, d);
        } else {
            deleteFinal(root->right, d);
        }
    }

    bool deleteBST(int data) {
        if (!root) return false;
        deleteFinal(root, data);
        return true;
    }

    bool searchBSTFinal(Node* root, int d) {
        if (!root) return false;
        if (root->data == d) {
            return true;
        } else if (root->data > d) {
            return searchBSTFinal(root->left, d);
        } else {
            return searchBSTFinal(root->right, d);
        }
    }

    bool searchBST(int data) {
        return searchBSTFinal(root, data);
    }
};

int main() {
    int n;
    cout << "Enter N" << endl;
    cin >> n;
    vector<int> vec(n);

    cout<<"Enter Node in BST"<<endl;
    for (int i = 0; i < n; i++) cin >> vec[i];

    BST tree;
    for (int i = 0; i < vec.size(); i++) {
        tree.insertBST(vec[i]);
    }

    int nodeToDelete;
    cout << "Enter Node You Want to delete" << endl;
    cin >> nodeToDelete;

    bool ans = tree.deleteBST(nodeToDelete);
    if (ans) cout << "Delete Successfully" << endl;
    else cout << "Not Delete Successfully" << endl;

    int s;
    cout << "Search Element" << endl;
    cin >> s;

    bool searchAns = tree.searchBST(s);
    if (searchAns) cout << "Exist" << endl;
    else cout << "Not Exist" << endl;

    return 0;
}
