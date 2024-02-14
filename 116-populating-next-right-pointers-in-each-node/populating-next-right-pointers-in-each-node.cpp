/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root ==NULL){
            return root;
        }
        // By Using level wise traversal 
        Node* curr = root;

        while(curr!=NULL && curr->left!=NULL){
            Node* tr = curr;

            while(true){
                tr->left->next = tr->right;

                if(tr->next==NULL){break;}
                tr->right->next = tr->next->left;

                tr = tr->next;
            }
            curr=curr->left;
        }    
        
        return root;

    }
};