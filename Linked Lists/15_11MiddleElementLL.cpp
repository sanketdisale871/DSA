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
        
      

        // handle case of empty or one node in list
        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // else if(head->next->next==NULL){ // handled the case of 2 nodes
        //     return head->next;
        // }else{

        //     ListNode *fast = head;
        //     ListNode *slow = head;

        //     while(fast->next!=NULL){

        //         // moving fast pointer two times and slow pointer one times
        //         fast = fast->next;
        //         slow=slow->next;

        //         if(fast->next!=NULL){
        //             fast = fast->next;
        //         }
        //     }

        //     return slow;
        // }

            ListNode *fast = head;
            ListNode *slow = head;

            while(fast!=NULL && fast->next !=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            return slow;

        
    }
};
