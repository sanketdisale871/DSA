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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // It's top pair is (minimunNode val,ListNode*)
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minHeap;

        for(auto li : lists){ // Storing first nodes from each list
            if(li != nullptr){
                minHeap.push({li->val,li});
            }
        }
        ListNode* dummy = new ListNode(-1); // Creating dummyNode
        ListNode* curr = dummy;

        while(!minHeap.empty()){
            ListNode* minNode = minHeap.top().second;
            minHeap.pop();

            if(minNode->next != nullptr){
                minHeap.push({minNode->next->val,minNode->next});
            }
            curr->next = minNode;
            curr = minNode;
        }
        return dummy->next;
    }

};
