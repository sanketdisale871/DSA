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
    int findHeight(TreeNode* root){
        // base case
        if(root == NULL){
            return 0;
        }

        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);

        return 1+max(lHeight,rHeight);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);

        if(lHeight == rHeight){
            return root;
        }
        else if(lHeight<rHeight){
            return lcaDeepestLeaves(root->right);
        }
        else{
            return lcaDeepestLeaves(root->left);
        }
    }
};