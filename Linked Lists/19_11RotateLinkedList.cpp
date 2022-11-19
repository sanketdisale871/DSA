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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // list have null or list have only one node or zero rotation
        
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        
        // finding length
        ListNode* curr = head;
        
        int len =1;
        while(curr->next!=NULL){
            len++;
            curr = curr->next;
        }
        
        // make circular linked list
        curr->next = head;
        
        k = k%len;
        k = len - k;
        
        while(k--){
            curr = curr->next;
        }
        
    // ab head ko next point karo curr ke
        head = curr->next;
        // nd curr ka next NULL kar do
        curr->next = NULL;
        
        return head;
            
    }
};
