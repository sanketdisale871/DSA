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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // if list 1 is null then return list 2
        if(list1==NULL){
            return list2;
        }

        // if list 2 is null then return list 1
        if(list2==NULL){
            return list1;
        }

        ListNode * ptr = list1;

        // positioning pointer 

        if(list1-> val > list2->val){
            ptr = list2;
            list2 = list2->next;
        }else{
            list1 = list1->next;
        }

        ListNode* curr = ptr;

        // till one of the list does not reaches the null
        while(list1 && list2){

            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }else{
                curr->next = list1;
                list1 = list1->next;                
            }
            curr = curr->next;
        }

    // remaining elements in list 1
        while(list1){
            curr->next = list1;
            list1 = list1->next;
            curr=curr->next;
        }
      // remaining elements in list 2
        while(list2){
            curr->next = list2;
            list2 = list2->next;
            curr=curr->next;
        }

        return ptr;   
    }
};
