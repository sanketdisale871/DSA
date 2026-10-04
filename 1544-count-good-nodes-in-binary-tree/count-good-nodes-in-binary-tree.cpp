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

    void traverse(TreeNode* root,int maxVal){
        if(root==NULL){
            return;
        }

        if(root->val >= maxVal){
            cnt++;
        }

        traverse(root->left, max(maxVal,root->val));
        traverse(root->right, max(maxVal,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        // node is Good => Path from root to X, there is no nodes with value greater than X.
        if(root==NULL){
            return 0;
        }

        traverse(root,root->val);

        return cnt;
    }
};