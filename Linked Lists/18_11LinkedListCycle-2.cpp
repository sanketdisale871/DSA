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
    ListNode *detectCycle(ListNode *head) {
        
        /* Approch 1 : Hash table 
        
        
        unordered_map<ListNode*,int>um;
        
        ListNode* temp = head;
        
        while(temp!=NULL && temp->next !=NULL){
            
            um[temp]++;
            
            if(um[temp]>1){
                return temp;
                break;
            }
            temp = temp->next;
        }
        return NULL;
        */
        
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast !=NULL && fast->next!=NULL && fast->next->next !=NULL){
            
            fast = fast->next->next;
            slow=slow->next;
            
           if(slow==fast){
                
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }
               return entry;
            }
        }
        return NULL;
    }
};
