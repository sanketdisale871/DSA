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
    int getDecimalValue(ListNode* head) {
        string str;

        ListNode* temp = head;

        while(temp!=NULL){
            str.push_back(temp->val +'0');
            temp = temp->next;
        }
        reverse(str.begin(),str.end());
        cout<<"str : "<<str<<endl;

        int ans = 0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='1'){
                ans = (ans|(1<<i));
            }
        }
        return ans;
    }
};