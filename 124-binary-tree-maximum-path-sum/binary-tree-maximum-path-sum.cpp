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
    int maxiSum=INT_MIN;
    int findMaxSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lef = max(0,findMaxSum(root->left));
        int rig  = max(0,findMaxSum(root->right));

        int t = root->val + lef+rig;
        maxiSum = max(maxiSum,t);

        return root->val + max(lef,rig);
    }
public:
    int maxPathSum(TreeNode* root) {

        if(root->left == NULL && root->right==NULL){
            return root->val;
        }
        
        findMaxSum(root);

        return maxiSum;
    }
};