#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = next;
    }
};

int main(){

    Node *node1= new Node(10);
    cout<<"Data Of node1 => "<<node1->data <<endl;
    cout<<"Address Of node1 => "<<node1->next <<endl;

    return 0;
}
