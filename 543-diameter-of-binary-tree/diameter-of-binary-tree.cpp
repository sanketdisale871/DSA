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
    int findLen(TreeNode* root,int &maxi){
        // Base case
        if(root==NULL){
            return 0;
        }

        int le = findLen(root->left,maxi);
        int ri = findLen(root->right,maxi);

        int res = le+ri;
        maxi = max(maxi,res);

        return 1+max(le,ri);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;

        findLen(root,maxi);

        return maxi;
    }
};