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
        Node* trav = root;

        while(trav!=NULL && trav->left!=NULL){
            Node* curr = trav;

            while(curr!=NULL){
                curr->left->next = curr->right;

                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            trav = trav->left;
        }
        return root;
    }
};