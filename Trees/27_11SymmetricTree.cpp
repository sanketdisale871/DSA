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
    
    bool IsSymmetric(TreeNode*leftroot,TreeNode*rightroot){
        
        // if both root node are null pointers, return true
        if(!leftroot && !rightroot){
            return true;
        }
        
        // if exactly one of them is null , return false
        if(!leftroot || !rightroot){
            return false;
        }
        
        // if roots haven't not same value
        if(leftroot->val != rightroot->val){
            return false;
        }
        

        return IsSymmetric(leftroot->left,rightroot->right) && IsSymmetric(leftroot->right,rightroot->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        // Special Case
        if(root==nullptr){
            return true;
        }
        
        // return the fucntion recursively
        return IsSymmetric(root->left,root->right);
    }
};
