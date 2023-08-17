#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;
    vector<vector<int>> ans;

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void findLongestPath() {
        vector<int> path;
        longestPathRec(root, path);

        vector<pair<int, int>> p;
        for (int i = 0; i < ans.size(); i++) {
            p.push_back({ans[i].size(), i});
        }

        sort(p.begin(), p.end(), greater<pair<int, int>>());
        int n = p[0].second;

        vector<int> finalans = ans[n];
        for (int i = 0; i < finalans.size(); i++) {
            cout << finalans[i] << " ";
        }
        cout << endl;
    }

private:
    Node* insertRec(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    void longestPathRec(Node* root, vector<int>& path) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->data);

        if (root->left == nullptr && root->right == nullptr) {
            // Leaf node reached, store the path
            ans.push_back(path);
        }

        longestPathRec(root->left, path);
        longestPathRec(root->right, path);

        path.pop_back();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BST bst;
    for (int num : arr) {
        bst.insert(num);
    }

    bst.findLongestPath();

    return 0;
}
