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
        // Other option can be : 
        // if(n==1){
        //     return NULL;
        // }
        // I will create achhese options 
        ListNode* prev = head;
        ListNode* nex = head;
        // ListNode* slow = head;

        while(n--){
            nex = nex->next;
        }

        if(nex==NULL){
            return head->next;
        }

        while(nex!=NULL && nex->next!=NULL){
            prev = prev->next;
            nex = nex->next;
        }

        ListNode* delNode = prev->next;
        prev->next = prev->next->next;

        delete delNode;

        return head;
        


    }
};