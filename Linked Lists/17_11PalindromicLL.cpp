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
    
    ListNode* reverseList(ListNode* &head){
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) {
        /* Optimal Approach : 
          i) : Find the middle element 
          ii) reverse the rigth half part
          iii) cmpare left and right part
        */
        
        // finding middle node 
        ListNode*slow = head;
        ListNode*fast = head;
        
        while(fast->next !=NULL && fast->next->next!=NULL){
                fast=fast->next->next;
                slow= slow->next;
        }
        
        // slow points the middle of list
        slow->next = reverseList(slow->next);
        
        // slow ko aage badhao
        slow = slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;        
    }
};
