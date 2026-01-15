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
    int cnt = 0;
    void traverse(TreeNode*root, int maxiNode){
        if(root==NULL){
            return;
        }

        if(root->val >= maxiNode){
            cnt++;
        }
        maxiNode = max(maxiNode,root->val);

        traverse(root->left,maxiNode);
        traverse(root->right,maxiNode);
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root,-1e5);

        return cnt;
    }
};