#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    // constructor

    Node(int val){
        this->data=val;
        this->prev=NULL;
        this->next=NULL;
    }

    /* Destructor */

    Node(){
        int val = this->data;

        if(this->next != NULL && this->prev !=NULL){
            delete next;
            delete prev;
            this->next=NULL;
            this->prev=NULL;            
        }
        cout<<"Memory is free for the node of the data : "<<val<<endl;
    }

};

/* Printing linked list */
void printll(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

/* Length of ll */
int getLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

/* Insert at head */

void insertAtHead(Node* &head,int val){
    Node* newNode= new Node(val);

    newNode->next=head;
    head->prev=newNode;
    head = newNode;
}

/* Insert at tail */

void insertAtTail(Node* &tail,int val){
    Node* newNode = new Node(val);

    tail->next=newNode;
    newNode->prev=tail;
    tail = newNode;
}

/* Insert at any Positon */

void insertAtAnyPosi(int posi,Node* &head,Node* &tail,int val){

    // jar first positon asel tar
    if(posi==1){
        insertAtHead(head,val);
        return;        
    }

    int cnt =1;
    Node* temp = head;

    while(cnt<(posi-1)){
        temp=temp->next;
        cnt++;
    }

    // jar last positon asel tar 
    if(temp->next == NULL){
        insertAtTail(tail,val);
        return;
    }

    // nahitar start and last madhil positon aahe
    Node* aageNode = temp->next;
    Node* newNode=new Node(val);

    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    aageNode->prev=newNode;
}


void deleteNode(int posi,Node* &head,Node* &tail){
    // if first wala node asel tar
    if(posi==1){
            Node*temp = head;
            temp->next->prev=NULL;
            head = temp->next;
            
            //nalla karke delete kardo
            temp->next=NULL;
            
            delete temp;
            return;
    }

    Node *curr =head;
    Node *pvs = NULL;
    int cnt = 1;
    while(cnt<posi){
        pvs=curr;
        curr=curr->next;
        cnt++;
    }

    // jar last wali position asel tar
    if(curr->next==NULL){
        tail=pvs;
        // nalla karke delete mar do
        curr->prev=NULL; 
        tail->next=NULL;
        delete curr;
        return;
    }

    // jar middle wali position asel tar
//     Node* aageCurr = curr->next;
    pvs->next = curr->next;
//     aageCurr->prev=pvs; this replaces by next line
    curr->next->prev=pvs;

    // nall karke delete mardo
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;

}

int main(){

    /* Creating doubly linked list */
    Node* newNode = new Node(7);

    Node* head = newNode;
    Node* tail = head;

    
    


/* Inserting at head */

    insertAtHead(head,15);
    insertAtHead(head,25);

/* Inserting at tail */
    insertAtTail(tail,50);
    insertAtTail(tail,100);

    /* insert at any position */

    insertAtAnyPosi(3,head,tail,27);
    insertAtAnyPosi(5,head,tail,200);
    insertAtAnyPosi(8,head,tail,45);
    insertAtAnyPosi(1,head,tail,45);

      printll(head);

    cout<<"\nHead poits to : "<<head->data;
    cout<<"\nTail poits to : "<<tail->data<<endl;

    /* Deletion of node */

    deleteNode(1,head,tail);
    deleteNode(5,head,tail);
    // deleteNode(1,head,tail);
 


    printll(head);
    cout<<"\nHead poits to : "<<head->data<<endl;
    cout<<"\nTail poits to : "<<tail->data<<endl;
    cout<<"Lenght of LL : "<<getLength(head)<<endl;
  
    return 0;
}
