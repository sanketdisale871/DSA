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
        // Base case
        if(root == NULL){
            return 0;
        }

        int lHeight = findHeight(root->left);
        int rHeight = findHeight(root->right);

        return 1+max(lHeight,rHeight);
    }
public:
    int maxDepth(TreeNode* root) {
        return findHeight(root);
    }
};