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
    int ans = 0;

    void traversal(TreeNode*root,int maxi){
        // base case
        if(root ==NULL){
            return ;
        }

        maxi = max(maxi,root->val);

        if(maxi<=root->val){
            ans++;
        }

        traversal(root->left,maxi);
        traversal(root->right,maxi);
    }
    
public:
    int goodNodes(TreeNode* root) {
        // int ans = 0;
        int maxi = INT_MIN;

        traversal(root,maxi);

        return ans;
    }
};