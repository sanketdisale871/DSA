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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;

        ListNode* itr = head;

        while(itr!=NULL){
            while(!st.empty() && st.top()->val < itr->val){
                st.pop();
            }
            st.push(itr);
            itr = itr->next;
        }

        ListNode* prev = NULL;

        while(!st.empty()){
            auto it = st.top();st.pop();
            it->next = prev;
            prev = it;
        }
        return prev;
    }
};