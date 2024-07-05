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
    bool isLocalMini(ListNode* prev,ListNode* curr){
        int prevVal = prev->val;
        int currVal = curr->val; 
        int nexVal = curr->next->val; 

        if(prevVal>currVal && currVal<nexVal){
            return true;
        }
        return false;
    }

    bool isLocalMax(ListNode* prev,ListNode* curr){
        int prevVal = prev->val;
        int currVal = curr->val; 
        int nexVal = curr->next->val; 

        if(prevVal<currVal && currVal>nexVal){
            return true;
        }
        return false;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;

        ListNode* curr = head;
        ListNode* prev = new ListNode(0);

        int posNum = 0;

        while(curr!=NULL){
            posNum++;

            if(posNum==1){
                prev = curr;
                curr=curr->next;
                continue;
            }

            if(curr->next==NULL){
                break;
            }
            if(isLocalMini(prev,curr) || isLocalMax(prev,curr)){
                ans.push_back(posNum);
            }

            prev = curr;
            curr=curr->next;            
        }

        if(ans.size()<2){
            return {-1,-1};
        }

        sort(ans.begin(),ans.end());

        // for(auto it:ans){
        //     cout<<it<<endl;
        // }

        int minDiff = INT_MAX;

        for(int i=1;i<ans.size();i++){
            int diff = ans[i]-ans[i-1];

            minDiff = min(minDiff,diff);
        }

        int maxDiff = ans[ans.size()-1]-ans[0];

        return {minDiff,maxDiff};
    }
};