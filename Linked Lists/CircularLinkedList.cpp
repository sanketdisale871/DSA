
#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // Constructor
    Node(int val){
        this->data=val;
        this->next=NULL;
    }

    // Destructor
    ~Node(){
        int val = this->data;

        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"\nDeleted the node for the data : "<<val<<endl;
    }
};

void insertCL(Node* &tail,int elem,int val){

    // if cl is empty
    if(tail==NULL){
        Node* newNode = new Node(val);
        newNode->next=newNode;
        tail =newNode;
    }else{
        Node* curr = tail;
        // assuming that we are given the elem

        while(curr->data!=elem){
            curr=curr->next;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next=newNode;

    }
}

void deleteNode(int val,Node* &tail){


    if(tail==NULL){
        /* if ll is empty*/
        cout<<"\nPlease cheack current linked list is empty.";
    }else{
        /* elemetn in list*/
    Node* prev =tail;
    Node* curr = prev ->next;

    while(curr->data!=val){
        prev = curr;
        curr=curr->next;
    }
   
    prev->next=curr->next;    

    //1 Node linked list
    if(curr==prev){
        tail=NULL;
    }    
    /* >=2 linked list */
    if(curr==tail){
        tail=prev;
    }
    curr->next=NULL;
    
    delete curr;
    }


}

/* Traversal the cl */

void printCL(Node* &tail){
    Node* temp = tail;

    if(temp==NULL){
        cout<<"List is empty.\n";
        return;
    }

    do{
        cout<<temp->data<<" ";
        temp = temp->next;

    }while(temp!=tail);
    cout<<endl;
}



int main(){

    Node* tail = NULL;

    insertCL(tail,1,7);
    insertCL(tail,7,8);
    // insertCL(tail,8,28);
    // insertCL(tail,28,38);
    // insertCL(tail,7,713);

    printCL(tail);

    // cout<<"\nAfter deletion of nodes in ll : \n"<<endl;

    // deleteNode(38,tail);
    deleteNode(7,tail);

    printCL(tail);


    return 0;
}
