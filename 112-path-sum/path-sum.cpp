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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case 
        if(root==NULL){
            return false;
        }

        if(root->left == NULL && root->right==NULL){

            if(targetSum-root->val==0){
                return true;
            }
            else{
                return false;
            }
        }

        bool leftWay =hasPathSum(root->left,targetSum-root->val); 
        if(leftWay){
            return true;
        }
        bool rightWay =hasPathSum(root->right,targetSum-root->val); 

        if(rightWay){
            return true;
        }

        return leftWay||rightWay;
    }
};