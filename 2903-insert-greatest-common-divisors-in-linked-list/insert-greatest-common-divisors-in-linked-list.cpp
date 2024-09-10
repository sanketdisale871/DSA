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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL){
            return head;
        }

        ListNode* prev = head;
        ListNode* nex = head->next;

        while(nex!=NULL){
            int r = __gcd(prev->val,nex->val);
            ListNode* newNode = new ListNode(r);

            newNode->next = nex;
            prev->next = newNode;

            prev=nex;
            nex = nex->next;
        }
        return head;
    }
};