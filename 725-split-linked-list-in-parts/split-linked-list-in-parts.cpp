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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        int len = 0;

        for(ListNode*node = head;node;node=node->next){
            len++;
        }

        int prt = len/k;
        int rem = len%k;

        ListNode* node = head;
        ListNode* prev = NULL;

        for(int i=0;i<k && node;i++){
            ans[i]=node;

            for(int j=0;j<prt+(rem>0);j++){
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
            rem--;
        }

        return ans;
    }
};