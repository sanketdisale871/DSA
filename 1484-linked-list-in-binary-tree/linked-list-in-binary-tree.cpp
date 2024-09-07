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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool ans = false;
    bool preOrdTraversal(ListNode *head,ListNode *temp,TreeNode* root){
        if(temp==NULL){
            return true;
        }

        if(root==NULL){
            return false;
        }

        if(root->val == temp->val){
            temp = temp->next;
        }
        else if(head->val == root->val){
            head = head->next;
        }
        else{
            temp = head;
        }

        return preOrdTraversal(head,temp,root->left) || preOrdTraversal(head,temp,root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* temp = head;
        return preOrdTraversal(head,temp,root);
      
    }
};