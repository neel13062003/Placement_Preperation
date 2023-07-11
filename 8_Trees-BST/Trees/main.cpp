#include <bits/stdc++.h>
using namespace std;


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
struct Node{
   int data;
   struct Node* left;
   struct Node* right;
};

//Constructor
Node* newNode(int data){
    Node* temp=new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}


//if vector<int> f(){ if(root==null) return ans;
void printInorder(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    printInorder(root->left,ans);
    ans.push_back(root->data);
    printInorder(root->right,ans);
}


void printPreorder(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    printPreorder(root->left,ans);
    printPreorder(root->right,ans);
}

void printPostorder(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    printPostorder(root->left,ans);
    printPostorder(root->right,ans);
    ans.push_back(root->data);
}

vector<int> inorder(Node* root){
   vector<int>ans;
   printInorder(root,ans);
   return ans;
}

vector<int> preorder(Node* root){
   vector<int> ans;
   printPreorder(root,ans);
   return ans;
}

vector<int> postorder(Node* root){
    vector<int>ans;
    printPostorder(root,ans);
    return ans;
}

int main()
{
    cout << "----------Tree------------" << endl;
    struct Node* root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);

    root->left->left= newNode(4);
    root->left->right= newNode(5);

    root->right->left= newNode(6);
    root->right->right= newNode(7);

    //print tree
    // root is given

    vector<int>vec1;
    vector<int>vec2;
    vector<int>vec3;
    vec1=inorder(root);
    vec2=preorder(root);
    vec3=postorder(root);

    for(int i=0;i<vec1.size();i++){
        cout<<vec1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<vec3.size();i++){
        cout<<vec3[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
