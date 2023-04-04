/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    // DSA Student : Sanket Disale
public:
// Approach 1 : Brute Force ( See the Strivers PDF )
// T.C : O (n)
// S.C : O (n)
    // Node* copyRandomList(Node* head) {

    //     unordered_map<Node*,Node*>um;

    //     Node* temp = head;
    //     // making the deep copies in hashmap
    //     while(temp!=NULL){
    //         Node* newNode = new Node(temp->val);
    //         um[temp]=newNode;

    //         temp = temp->next;
    //     }
    //     // acess the nodes and point next and random according
    //     Node* t = head;
    //     while(t!=NULL){
    //         Node* node = um[t];

    //         node->next = (t->next != NULL) ? um[t->next] : nullptr;
    //         node->random = (t->random!=NULL) ?um[t->random]:nullptr;

    //         t = t->next;
    //     }

    //     return um[head];
    // }

    /* Approach 2 : Optimised Approach
        T.C. : O(n) (Creating deep nodes ) + O(n) (random pointer pointign) +O (n) (make the sepration)
        S.C : O(1)
    */

     Node* copyRandomList(Node* head){
         // Step 1 : make the deap copy nodes
         Node* temp = head;

         while(temp!=NULL){
             Node* newNode = new Node(temp->val);
             newNode->next = temp->next;
             temp->next = newNode;

             temp = temp->next->next;
         }

         // Step 2 : make the deep copy random pointer
         Node* itr = head;

         while(itr!=NULL){
             if(itr->random != NULL){
                 itr->next->random = itr->random->next;
             }
             itr = itr->next->next;
         }

         // Step 3 : make the sepration between to lists
         Node* dummy = new Node(0);
            temp = dummy;

        itr = head;
        Node* fast;

        while(itr != NULL){
            fast = itr->next->next;
            temp->next =itr->next;
            itr->next = fast;

            itr = fast;
            temp = temp->next;
        }

        return dummy->next;

     }
};
