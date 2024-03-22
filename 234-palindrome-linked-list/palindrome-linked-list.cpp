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
public:
/* Approach : 
    1) Middle of LL
    2) Reverse LL (midd-end)
    3) Check (ori & revLL)
*/  
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slow = head; // This go one Step 
        ListNode* fast = head; // Two Step 

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* revList(ListNode* middNode){
        ListNode* prev = NULL;
        ListNode* curr = middNode;
        ListNode* nextNode = middNode->next;

        while(curr){
            curr->next = prev;

            prev = curr;
            curr = nextNode;

            if(nextNode==NULL){
                continue;
            }
            else{
                nextNode = nextNode->next;
            }
        }
        return prev;
    }


    bool isPalindrome(ListNode* head) {
        
        ListNode* middNode = findMiddleNode(head); // Middle Node
        ListNode* revHead = revList(middNode); // Starting Node of Reverse LL 


        ListNode* oriItr = head;
        ListNode* revItr = revHead;

        while(oriItr!=NULL && revItr!=NULL){
            if(oriItr->val != revItr->val){
                return false;
            }
            oriItr = oriItr->next; 
            revItr = revItr->next;
        }

        return true;
    }
};