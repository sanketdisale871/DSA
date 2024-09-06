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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>elems(nums.begin(),nums.end());

        while(head!=NULL && elems.count(head->val)){
            head = head->next;
        }

        ListNode* temp = head;

        while(temp!=NULL && temp->next!=NULL){
            ListNode* itr = temp->next;
            while(itr!=NULL && elems.count(itr->val)){
                itr = itr->next;
            }
            temp->next = itr;
            temp = temp->next;
        }

        return head;
    }
};