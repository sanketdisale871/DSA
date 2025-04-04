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
        if(root == NULL){
            return 0;
        }

        int lefHt = findHeight(root->left);
        int righHt = findHeight(root->right);

        return 1+max(lefHt,righHt);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        int lHt = findHeight(root->left);
        int rHt = findHeight(root->right);

        if(lHt==rHt){
            return root;
        }
        else if(lHt<rHt){
            return lcaDeepestLeaves(root->right);
        }
        else{
            return lcaDeepestLeaves(root->left);
        }

    }
};