/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightNode = lowestCommonAncestor(root->right,p,q);

        if(leftNode!=NULL && rightNode!=NULL){
            return root;
        }
        else if(leftNode!=NULL){
            return leftNode;
        }
        else if(rightNode!=NULL){
            return rightNode;
        }
        else{
            return NULL;
        }
    }
};