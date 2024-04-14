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
    int leftNodeSum = 0;

    void doTrav(TreeNode* root,bool isLef){
        if(root==NULL){
            return ;
        }

        if(root->left ==NULL && root->right==NULL){
            if(isLef){
                leftNodeSum+=root->val;
            }
            return;
        }

        doTrav(root->left,true);
        doTrav(root->right,false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        bool isLef = false;
        doTrav(root,isLef);

        return leftNodeSum;
    }
};