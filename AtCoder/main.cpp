#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
private:
    Node* root;
    vector<vector<int>>ans;
public:
    BST(){
        root = nullptr;
    }

    void insertTreeNodeCall(int value){
         root = insertNode(root,value);
    }

    Node* insertNode(Node* root,int value){
        if(root == nullptr){
            return new Node(value);
        }

        if(value < root->data){
            root->left = insertNode(root->left,value);
        }else if(value > root->data){
            root->right = insertNode(root->right,value);
        }
        return root;
    }

    void longestPathCall(){
        vector<int>path;
        longestPath(root,path);

        vector<pair<int,int>>p;
        for(int i=0;i<ans.size();i++){
            p.push_back({ans[i].size(),i});
        }

        sort(p.begin(), p.end(), greater<pair<int, int>>());
        int n = p[0].second;

        vector<int> finalans = ans[n];
        for (int i = 0; i < finalans.size(); i++) {
            cout << finalans[i] << " ";
        }
        cout << endl;
    }

    void longestPath(Node* root,vector<int>&path){
        if(root == nullptr) return;
        path.push_back(root->data);

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
        }

        longestPath(root->left,path);
        longestPath(root->right,path);
        path.pop_back();
    }

};

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i=0;i<n;i++)cin>>vec[i];

    BST bst;
    for(int i=0;i<vec.size();i++){
        bst.insertTreeNodeCall(vec[i]);
    }

    bst.longestPathCall();

    return 0;
}
