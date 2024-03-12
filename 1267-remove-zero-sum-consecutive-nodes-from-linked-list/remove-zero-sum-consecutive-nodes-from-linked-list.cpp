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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* newHead = NULL;

        ListNode* t1 = new ListNode(-1);
        t1->next = head;

        while(t1!=NULL){
            ListNode* t2 = t1->next;
            ListNode* t3 = NULL;
            int sum = 0;
            bool isSum = false;

            while(t2!=NULL){
                sum+=(t2->val);

                if(sum==0){
                    isSum = true;
                    t3 = t2;
                    // break;
                }
                t2=t2->next;
            }

            if(isSum){
                t1->next = t3->next;
            }

            t1 = t1->next;
            if(newHead == NULL){
                newHead = t1;
            }
        }
        // return newHeadl;
        return newHead;
    }
};