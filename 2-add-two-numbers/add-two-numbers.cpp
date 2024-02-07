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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        
        int car = 0;

        while(l1 && l2){
            int val = l1->val + l2->val + car;

            car = val/10;
            val = val%10;

            ListNode* newNode = new ListNode(val);
            curr->next = newNode;
            curr = curr->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int val = l1->val + car;

            car = val/10;
            val = val%10;

            ListNode* newNode = new ListNode(val);
            curr->next = newNode;
            curr = curr->next;
            l1 = l1->next;
        }

        while(l2){
            int val = l2->val + car;

            car = val/10;
            val = val%10;

            ListNode* newNode = new ListNode(val);
            curr->next = newNode;
            curr = curr->next;
            l2 = l2->next;
        }

        while(car){
            int val = car;

            car = val/10;
            val = val%10;

            ListNode* newNode = new ListNode(val);
            curr->next = newNode;
            curr = curr->next;
            // l2 = l2->next;
        }

        return temp->next;
    }
};