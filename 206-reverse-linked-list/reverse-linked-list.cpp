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
    ListNode* ans;
    void revList(ListNode* head,ListNode* prev){
        if(head ==NULL){
            ans = prev;
            return ;
        }

        revList(head->next,head);

        head->next=prev;
    }

public:
    ListNode* reverseList(ListNode* head) {
        // Edge case ;
        if(head==NULL || head->next == NULL){
            return head;
        }

        revList(head,NULL);

        return ans;
    }
};