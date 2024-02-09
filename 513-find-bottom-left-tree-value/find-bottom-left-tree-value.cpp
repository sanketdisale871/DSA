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

    void findLeft(TreeNode*root,int &height,int depth,int &ans){
        if(root==NULL){
            return ;
        }
        // base case
        if(depth>height){
            ans = root->val;
            height = depth;
        }

        findLeft(root->left,height,depth+1,ans);

        findLeft(root->right,height,depth+1,ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        int height = -1;
        int depth = 0;

        findLeft(root,height,depth,ans);

        return ans;
    }
};