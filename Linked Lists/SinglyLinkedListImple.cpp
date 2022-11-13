#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // costructor
    Node(int val){
        this->data=val;
        this->next=NULL;
    }

    // destructor
    Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }

        cout<<"Memory is Free for node with data : "<<val<<endl;
    }

};

/* Insertion operation in linked list */

// 1] insert at head

void insertAtHead(int val,Node* &head){

    Node* newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}

// 2]  insert at end position
void insertAtTail(int val,Node* &tail){
    
    Node* newNode = new Node(val);
    tail->next=newNode;
    tail = newNode;
}

// 3] insert at any position

void insertAtAnyPosition(int posi,int val,Node* &head,Node* &tail){

    // if position is first
    if(posi==1){
        insertAtHead(val,head);
        return;
    }
    int cnt =1;
    Node* temp = head;

    while(cnt<(posi-1)){
        temp=temp->next;
        cnt++;
    }

    // if the position is last
    if(temp->next==NULL){
            insertAtTail(val,tail);
            return;
    }

    // ab middle mai se hi position hogi
    Node* newNode = new Node(val);

        newNode->next=temp->next;
        temp->next=newNode;

}


/* Delete node from linked list */

void deleteNode(int posi,Node* &head,Node* &tail){

    // jr position first asel tar
    if(posi==1){
        Node* temp = head;
        head = temp->next;

        // nalla kar ke delete mardo
        temp->next=NULL;
        delete temp;
    }else{
        Node* curr =head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt<posi){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        // jr ti last position asel tar tail ko update kar diya
        if(curr->next==NULL){
            tail = prev;
        }

            prev->next = curr->next;

            // nall kar ke delete mar do
            curr->next = NULL;
            delete curr;
    }
}

void printll(Node* &head){

    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *newNode = new Node(10);

    Node* head,*tail;
    head = tail = NULL;

    head = newNode;
    tail = head;

    insertAtHead(5,head);
    insertAtTail(55,tail);
    insertAtAnyPosition(2,550,head,tail);
    insertAtAnyPosition(5,560,head,tail);
    insertAtAnyPosition(1,5000,head,tail);
    printll(head);

    cout<<"\nHead points to : "<<head->data<<endl;
    cout<<"\nTail points to : "<<tail->data<<endl;

    deleteNode(1,head,tail);
    printll(head);
    cout<<"\nHead points to : "<<head->data<<endl;
    cout<<"\nTail points to : "<<tail->data<<endl;




    return 0;
}
