/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        /* 1st approach : 
            i) store the address of node in hash map and in traversing we got same address then it cyclic ll.        
        
        */
        
        /*
        unordered_map<ListNode*,int>um;
        
        while(head!=NULL){
            um[head]++;
            
            if(um[head]>1){
                return true;
            }
            head=head->next;
        }
        return false;
        */
        
        /*Second approach : T.C : O(n)
        S.C = O(1)
        
            i) we storing speciffic value in node where head is pointing , if we traversed that value then again then it cyclic in nature.
        */
        /*
        
        while(head!=NULL){
            
            if(head->val == 1e5+7){
                return true;
            }
            
            head->val = 1e5+7;
            head = head->next;
                
        }
        return false;
        */
        
        
        /* Approach 3 : Fast and slow Pointer (two ptr approach)
        Traverse linked list using two pointers.
        Move one pointer(slow_p) by one and another pointer(fast_p) by two.
        If these pointers meet at the same node then there is a loop. If pointers do not meet  then linked list doesn’t have a loop.
        
        */
        
        // if head is NULL then return false;

        if(head==NULL){
            return false;
        }
        
        // making two pointers fast and slow and assignning them to head
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow){
                return true;
            }
            
        }
        return false;
        
    }
};
