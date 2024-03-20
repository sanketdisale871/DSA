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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevItr = list1;
        ListNode* nextItr = list1->next;

        int diff = b-a;
        while(diff--){
            nextItr=nextItr->next;
        }

        int dist = a-1;

        while(dist--){
            prevItr = prevItr->next;
            nextItr = nextItr->next;
        }

        ListNode* endNodeLst2 = list2;

        while(endNodeLst2!=NULL && endNodeLst2->next!=NULL){
            endNodeLst2=endNodeLst2->next;
        }

        prevItr->next = list2;
        endNodeLst2->next = nextItr->next;
        nextItr->next = NULL;


        return list1;
    }
};