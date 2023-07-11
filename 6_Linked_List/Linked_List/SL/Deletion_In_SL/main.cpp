#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //Destructor
    ~Node(){
        int value= this->data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node value "<< value <<endl;
    }

};


void insert_at_head(Node*& head,int d){
    Node* temp= new Node(d);
    temp->next = head;
    head= temp;
}

void insert_at_tail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next= temp;
    tail= tail->next;
}

void insert_at_position(Node* &tail, Node* &head, int d, int position){

    //insert at first position
    if(position==1){
        insert_at_head(head,d);
        return;
    }

    Node* temp= head;
    int count=1;

    while(count<position-1){
        temp = temp->next;
        count++;
    }

    //insert at last position
    if(temp->next==NULL){
        insert_at_tail(tail,d);
        return;
    }

    Node* nodeToinsert = new Node(d);
    nodeToinsert-> next=  temp->next;
    temp->next= nodeToinsert;
}



void  deleteNode(int position, Node* &head){
    //deleting first or start node
    if(position==1){
        Node* temp = head;              //store head node data in temp node
        head = head -> next;            //update head node


        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    //deleting any middle node or last node
    else{
        //deleting any middle node or last node
        Node* curr= head;
        Node* prev = NULL;

        //Looping and Count mechanism
        int count=0;
        while(count<position){
            prev= curr;
            curr= curr->next;
            count++;
        }

        prev->next = curr-> next;
        curr->next =  NULL;
        delete curr;
    }
}



void print(Node* &head){
    //print through traversing from head via temp

    Node* temp = head;

    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp= temp-> next;
    }
}


int main(){

    Node* node1 = new Node(10);    //10


    Node *head= node1;
    Node *tail= node1;
    print(head);


    insert_at_head(head,20);        //20 10
    print(head);
    cout<<endl;

    insert_at_tail(tail,30);        //20 10 30
    print(head);
    cout<<endl;

    insert_at_position(tail,head,40,2);  // 20 40 10 30
    print(head);
    cout<<endl;

    deleteNode(1,head);
    print(head);
    cout<<endl;


    return 0;
}
