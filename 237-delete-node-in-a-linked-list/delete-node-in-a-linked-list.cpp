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
    void deleteNode(ListNode* node) {
        ListNode* itr = node;
        ListNode* prev = new ListNode(-1);

        while(itr!=NULL && itr->next!=NULL){
            itr->val = itr->next->val;
            prev = itr;
            itr = itr->next;
        }

        prev->next = NULL;
    }
};