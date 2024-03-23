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
    private:
    ListNode* reverseList(ListNode* head){
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r = head->next;

        while(q!=NULL){
            q->next = p;
            p = q;
            q = r;

            if(r==NULL){
                continue;
            }
            else{
                r = r->next;
            }
        }
        return p;
    }
public:
    void reorderList(ListNode* head) {
        /*
        Approach ; 
        1) Find middle Node of LL
        2) Break Make two Sep. LL
        3) Reorder        
        */

        if(head->next == NULL || head->next->next==NULL){
            return ;
        }

        ListNode* slow = head;
        ListNode* fast =head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast->next!=NULL){
            fast =fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if(fast!=NULL){ // odd length LL 
            prev = slow;
            slow = slow->next;
        }

        prev->next = NULL;

        slow = reverseList(slow);


        ListNode* ListItr1 = head;
        ListNode* ListItr2 = slow;
        ListNode* ListNextItr1 = head->next;
        ListNode* ListNextItr2 = slow->next;


        while(ListItr1!=NULL && ListItr2!=NULL){
            cout<<"FirstLIstTrav "<<ListItr1->val<<endl;
            cout<<"SecondLIstTrav "<<ListItr2->val<<endl;
            ListItr1->next = ListItr2;
            ListItr2->next = ListNextItr1;
            ListItr1=ListNextItr1;
            ListItr2=ListNextItr2;

            if(ListNextItr1){
                ListNextItr1=ListNextItr1->next;
            }

            if(ListNextItr2){
                ListNextItr2=ListNextItr2->next;
            }
        }


    }
};