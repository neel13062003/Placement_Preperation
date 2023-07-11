https://leetcode.com/discuss/interview-question/algorithms/125084/given-a-binary-search-tree-find-the-distance-between-2-nodes

https://practice.geeksforgeeks.org/problems/find-the-distance-between-two-nodes4402/1

class Solution {
public:
    int findDistance(Node* root, int k, int level) {
        if (root == nullptr) return -1;
        if (root->data == k) return level;

        int left = findDistance(root->left, k, level + 1);
        if (left == -1) return findDistance(root->right, k, level + 1);
        return left;
    }

    int distance(Node* root, int X, int Y) {
        Node* lowestCommonAncestor = findLCA(root, X, Y);
        int distX = findDistance(lowestCommonAncestor, X, 0);
        int distY = findDistance(lowestCommonAncestor, Y, 0);

        return distX + distY;
    }

    Node* findLCA(Node* root, int X, int Y) {
        if (root == nullptr) return nullptr;
        if (root->data == X || root->data == Y) return root;

        Node* left = findLCA(root->left, X, Y);
        Node* right = findLCA(root->right, X, Y);

        if (left != nullptr && right != nullptr) return root;
        if (left == nullptr && right == nullptr) return nullptr;

        return (left != nullptr) ? left : right;
    }
};
