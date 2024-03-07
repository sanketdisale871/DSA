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
    ListNode* middleNode(ListNode* head) {
        int listLength = 0;
        ListNode* itrNode = head;

        while(itrNode!=NULL){
            listLength++;
            itrNode=itrNode->next;
        }

        int middleListNode = listLength/2;

        ListNode* middleNode;
        itrNode = head;

        while(middleListNode--){
            itrNode = itrNode->next;
            middleNode = itrNode;
        }

        return middleNode;
    }
};