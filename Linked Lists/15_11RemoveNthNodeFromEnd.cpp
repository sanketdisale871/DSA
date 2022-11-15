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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyNode = new ListNode();

        dummyNode->next = head;

        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;

        // n iteration tak n ko badhao
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
          
      // handle head Node : if deletion of first element
        if(fast->next==NULL){
            return head->next;
        }

        while(fast->next!=NULL){
            fast = fast->next;
            slow=slow->next;
        }

        slow->next = slow->next->next;

        return head;
        
    }
};
