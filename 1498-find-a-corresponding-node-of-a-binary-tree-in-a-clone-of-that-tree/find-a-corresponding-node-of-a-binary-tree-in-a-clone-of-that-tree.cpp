/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    TreeNode* ans;
    void traverse(TreeNode* ori, TreeNode* clo, TreeNode* target){

        if(ori==NULL || clo==NULL){
            return ;
        }

        if(ori->val == target->val && clo->val == target->val){
            ans= clo;
            return;
        }

        traverse(ori->left,clo->left,target);
        traverse(ori->right,clo->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* ori, TreeNode* clo, TreeNode* target) {
   
        traverse(ori,clo,target);

        return ans;
    }
};