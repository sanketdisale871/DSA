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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* ans = new ListNode(-1);

        ListNode* ress = ans;

        while(l1!=NULL && l2!=NULL){
            int res = l1->val+l2->val + carry;
            carry = res/10;
            int dig = res%10;
            cout<<"dig : "<<dig<<endl;
            ListNode* newNode = new ListNode(dig);
            ans->next = newNode;
            ans = ans->next;
            l1=l1->next;
            l2 = l2->next;
        }

        while(l1!=NULL){
            int res = l1->val+ carry;
            carry = res/10;
            int dig = res%10;
            ListNode* newNode = new ListNode(dig);
             cout<<"dig : "<<dig<<endl;
            ans->next = newNode;
            ans = ans->next;
            l1=l1->next;
        }

        while(l2!=NULL){
            int res = l2->val+ carry;
            carry = res/10;
            int dig = res%10;
            ListNode* newNode = new ListNode(dig);
             cout<<"dig : "<<dig<<endl;
            ans->next = newNode;
            ans = ans->next;
            l2=l2->next;
        }

        if(carry){
             ListNode* newNode = new ListNode(carry);
          
            ans->next = newNode;
            ans = ans->next;
        }

        

        return ress->next;
    }
};