#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node * next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void  insert_At_Head(  Node* &head , int d ){
    //new node create
    Node* temp= new Node(d);
    temp->next = head;
    head = temp;
}

void insert_At_Tail( Node* &tail, int d){
    //new Node create
    Node* temp= new Node(d);
    tail-> next =  temp;
    tail = tail ->next;
}


void insert_At_Position( Node* &tail,Node* &head , int position, int d){

    //Insert at start
    if(position==1){
        insert_At_Head(head,d);
        return ;
    }


    Node* temp= head;
    int cnt=1;

    while(cnt< position-1){
        temp = temp->next;
        cnt++;
    }

    //insert at last position
    if(temp->next== NULL){
        insert_At_Tail(tail,d);
        return ;
    }




    //creating  a node for d
    Node* nodeToinsert= new Node(d);
    nodeToinsert-> next =  temp->next;
    temp->next = nodeToinsert;

}


void print(Node* &head){
    Node* temp = head;

    while(temp!= NULL){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1= new Node(10);
    /*cout<<"Data Of node1 => "<<node1->data <<endl;
    cout<<"Address Of node1 => "<<node1->next <<endl;*/


    //Head Pointed to node1
    Node* head = node1;

    Node* tail = node1;

    print(head);

    insert_At_Head(head,12);
    print(head);

    insert_At_Head(head,13);        // 13 12 10
    print(head);

    insert_At_Tail(tail,14);        // 13 12 10 14
    print(head);


    insert_At_Position(tail,head, 2 , 20);  // 13 20 12 10 14
    print(head);



    return 0;
}
