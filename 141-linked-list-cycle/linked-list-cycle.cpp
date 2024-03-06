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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>nodesCnt;

        ListNode* temp = head;

        while(temp!=NULL){
            nodesCnt[temp]++;

            if(nodesCnt[temp]>1){
                return true;
            }
            temp = temp->next;
        }
        
        return false;
    }
};