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
        if(head->next==NULL){
            return NULL;
        }

        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        for(int i=1;i<=n;i++){
            fastPtr = fastPtr->next;
        }

        if(fastPtr==NULL){ // If whole length traverse, i have to delete Head of LinkedList
            return head->next;
        }

        while(fastPtr!=NULL && fastPtr->next!=NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        ListNode* delNode = slowPtr->next;
        slowPtr->next = slowPtr->next->next;

        delNode->next = NULL;
        delete delNode;

        return head;
    }
};