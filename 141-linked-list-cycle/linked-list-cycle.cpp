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

      // T.C: o(n) S.C : O(1)

      ListNode* slow = head; // Moves next by one step
      ListNode* fast = head; // Moves next by two step 

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};