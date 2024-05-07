/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode* reverseList(ListNode* head){
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r = head->next;

        while(q){
            q->next = p;
            p = q;
            q = r;

            if(r==NULL){
                continue;
            }
            else{
                r = r->next;
            }
        }
        return p;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        /*
        Approch : 
        1) Reverse
        2) Do doubling
        3) Reverse 
        4) Remove leading zeroes 
        5 ) return head;        
        */

        ListNode* revNode = reverseList(head);

        int cary = 0;

        ListNode* travNode = revNode;
        ListNode* prev = NULL;

        while(travNode!=NULL){
            int vale = (travNode->val)*2 + cary;

            int digit = vale%10;
            cary = vale/10;

            travNode->val = digit;
            prev=travNode;
            travNode=travNode->next;
        }

        if(cary){
            prev->next = new ListNode(cary);
            prev = prev->next;
        }

        head = reverseList(revNode);

        return head;
    }
};