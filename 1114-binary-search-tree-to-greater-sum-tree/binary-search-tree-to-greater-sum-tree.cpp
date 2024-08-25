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
    typedef long long int ll;
    ll prevSum = 0;

    void doApnaWork(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        doApnaWork(root->right);
        prevSum += root->val;

        root->val = prevSum;

        doApnaWork(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL){
            return root;
        }

        doApnaWork(root);

        return root;
    }
};