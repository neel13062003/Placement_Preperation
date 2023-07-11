#include <bits/stdc++.h>
using namespace std;

/*
<> Preorder		Root -> Left -> Right 
<> Inorder		Left -> Root -> Right
<> Postorder	Left -> Right -> Root
*/

// A binary tree node has data, pointer to left child and a pointer to right child 
struct Node{
    int data;
    struct Node*left,*right;
}

// Utility function to create a new tree node
Node* newNode(int data){
    Node* temp = new Node(data);
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* node){ 
    if(node==NULL) return;

    inorder(node->left);
    cout<< node->data << " " <<endl;
    inorder(node->right);
}


void preorder(struct Node* node){
    if(node==NULL) return;

    cout<< node->data << " " <<endl;
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node){
    if(node==NULL) return;

    postorder(node->left);
    postorder(node->right);
    cout<< node->data << " " <<endl;
}

int main(){
    
    struct Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(5);


    cout<<"Inorder"<<endl;
    inorder(root);

    cout<<"Preorder"<<endl;
    preorder(root);

    cout<<"Postorder"<<endl;
    postorder(root);
    return 0;
}